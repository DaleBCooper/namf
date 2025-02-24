#include "testable.h"
#include <unity.h>

void setUp() {};
void tearDown() {};
void test_hours(){
    TEST_ASSERT_TRUE(hourIsInRange(23,20,6));
    TEST_ASSERT_TRUE(hourIsInRange(23,20,23));
    TEST_ASSERT_FALSE(hourIsInRange(18,20,23));
    TEST_ASSERT_FALSE(hourIsInRange(18,20,16));
    TEST_ASSERT_FALSE(hourIsInRange(1,20,24));
}

void test_switch_hysteresis() {
    TEST_ASSERT_TRUE(alarmState(100, 10, false, 110));
    TEST_ASSERT_TRUE(alarmState(100, 10, false, 120));
    TEST_ASSERT_FALSE(alarmState(100, 10, false, 105));
    TEST_ASSERT_FALSE(alarmState(100, 10, false, 100));
    TEST_ASSERT_FALSE(alarmState(100, 10, false, 95));
    TEST_ASSERT_FALSE(alarmState(100, 10, false, 90));
    TEST_ASSERT_FALSE(alarmState(100, 10, false, 80));

    TEST_ASSERT_FALSE(alarmState(100, 10, true, 80));
    TEST_ASSERT_FALSE(alarmState(100, 10, true, 90));
    TEST_ASSERT_TRUE(alarmState(100, 10, true, 92));
    TEST_ASSERT_TRUE(alarmState(100, 10, true, 100));
    TEST_ASSERT_TRUE(alarmState(100, 10, true, 109));
    TEST_ASSERT_TRUE(alarmState(100, 10, true, 110));
    TEST_ASSERT_TRUE(alarmState(100, 10, true, 112));
}

int main( int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_hours);
    RUN_TEST(test_switch_hysteresis);
    UNITY_END();
}