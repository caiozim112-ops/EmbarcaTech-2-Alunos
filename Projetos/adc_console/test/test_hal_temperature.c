#include "unity.h"
#include "ler_temperatura.h"

void setUp(void) {}
void tearDown(void) {}

void test_adc_to_celsius_should_return_27_when_voltage_is_0_706(void) {
    const float voltage = 0.706f;
    const float expected = 27.0f;
    const float tolerance = 0.1f;

    float result = adc_to_celsius(voltage);
    TEST_ASSERT_FLOAT_WITHIN(tolerance, expected, result);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_adc_to_celsius_should_return_27_when_voltage_is_0_706);
    return UNITY_END();
}
