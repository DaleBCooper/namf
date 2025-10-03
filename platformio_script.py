Import("env")
from os.path import basename

import os
import shutil

try:
    import configparser
except ImportError:
    import ConfigParser as configparser

# print(env.Dump())
# print (projenv.Dump())

config = configparser.ConfigParser()
config.read("platformio.ini")

flags = " ".join(env['LINKFLAGS'])
flags = flags.replace("-u _printf_float", "")
flags = flags.replace("-u _scanf_float", "")
newflags = flags.split()
env.Replace(
    LINKFLAGS=newflags
)


def after_build(source, target, env):
    # f = open('version.txt', 'r')
    # val = (f.read()).split(' ', 2)
    # print(val)
    firmware_path = str(target[0].path)
    firmware_name = basename(firmware_path)

    os.makedirs("./builds/ESP32", exist_ok=True)
    os.makedirs("./builds/ESP8266", exist_ok=True)
    # dir = "ESP8266"
    if env["PIOPLATFORM"] == "espressif8266" :
        dir = "ESP8266"
    else:
        dir = "ESP32"
    configName = env['PIOENV']  #something (SCons?) have changed in Platformio 6.1.16?
    sectionName = 'env:' + configName
    lang = config.get(sectionName, "lang").lower()
    dest = 'builds/{d}/latest_{l}.bin'.format(d=dir, l=lang)
    print("Uploading {0} to {1}".format(firmware_name, dest))
    shutil.copy(target[0].path, dest)

    firmware_path = str(source[0].path)
    firmware_name = basename(firmware_path)
    dest = 'builds/{d}/latest_{l}.elf'.format(d=dir, l=lang)
    print("Uploading {0} to {1}".format(firmware_name, dest))
    shutil.copy(source[0].path, dest)
    # breakpoint()


env.AddPostAction("$BUILD_DIR/firmware.bin", after_build)
