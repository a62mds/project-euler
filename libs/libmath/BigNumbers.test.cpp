#include "doctest.h"

#include "BigNumbers.h"


TEST_CASE("Test math::bignumbers::BigNumber constructor") {

    SUBCASE("Valid number") {
        CHECK_NOTHROW(math::bignumbers::BigNumber("938475394747489283757293847492938447293847492783649"));
    }

    SUBCASE("Invalid number (empty string))") {
        CHECK_THROWS_AS(math::bignumbers::BigNumber(""), std::invalid_argument);
    }

    SUBCASE("Invalid number with letters") {
        CHECK_THROWS_AS(math::bignumbers::BigNumber("9384abc"), std::invalid_argument);
    }

    SUBCASE("Invalid number with whitespace") {
        CHECK_THROWS_AS(math::bignumbers::BigNumber("9384   "), std::invalid_argument);
    }

    SUBCASE("Invalid number with symbols") {
        CHECK_THROWS_AS(math::bignumbers::BigNumber("9384!@#"), std::invalid_argument);
    }
}


TEST_CASE("Test math::bignumbers::BigNumber::to_string") {

    SUBCASE("Single digit") {
        std::string zero_str = "0";
        math::bignumbers::BigNumber zero(zero_str);

        CHECK_EQ(zero.to_string(), zero_str);
    }

    SUBCASE("Many digits") {
        std::string number_str = "8475729384720384724847";
        math::bignumbers::BigNumber number(number_str);

        CHECK_EQ(number.to_string(), number_str);
    }

    SUBCASE("Strip leading zeros") {
        std::string number_with_leading_zeros = "000002834473204";
        std::string number_without_leading_zeros = "2834473204";
        math::bignumbers::BigNumber number(number_with_leading_zeros);

        CHECK_EQ(number.to_string(), number_without_leading_zeros);
    }

    SUBCASE("String of multiple zeros gives zero") {
        std::string zeros = "00000000000";
        std::string zero = "0";
        math::bignumbers::BigNumber number(zeros);

        CHECK_EQ(number.to_string(), zero);
    }
}

TEST_CASE("Test math::bignumbers::BigNumber::num_digits") {

    SUBCASE("Single digit numbers") {
        math::bignumbers::BigNumber zero("0");
        math::bignumbers::BigNumber five("5");
        math::bignumbers::BigNumber nine("9");

        CHECK_EQ(zero.num_digits(), 1);
        CHECK_EQ(five.num_digits(), 1);
        CHECK_EQ(nine.num_digits(), 1);
    }

    SUBCASE("Five digit numbers") {
        math::bignumbers::BigNumber ten_thousand("10000");
        math::bignumbers::BigNumber fifty_thousand("50000");
        math::bignumbers::BigNumber five_nines("99999");

        CHECK_EQ(ten_thousand.num_digits(), 5);
        CHECK_EQ(fifty_thousand.num_digits(), 5);
        CHECK_EQ(five_nines.num_digits(), 5);
    }

    SUBCASE("Many digit numbers") {
        math::bignumbers::BigNumber eleven_nines("99999999999");
        math::bignumbers::BigNumber twenty_three_digit_number("27384759485768594859673");

        CHECK_EQ(eleven_nines.num_digits(), 11);
        CHECK_EQ(twenty_three_digit_number.num_digits(), 23);
    }
}

TEST_CASE("Test math::bignumbers::BigNumber::operator==") {

    SUBCASE("Single instance is equal to itself") {
        math::bignumbers::BigNumber zero("0");

        CHECK_EQ(zero, zero);
    }

    SUBCASE("Different instances of same number are equal") {
        math::bignumbers::BigNumber num1("12345");
        math::bignumbers::BigNumber num2("12345");

        CHECK_EQ(num1, num2);
    }
}

TEST_CASE("Test math::bignumbers::BigNumber::operator+") {

    SUBCASE("0 + 0 = 0") {
        math::bignumbers::BigNumber zero("0");

        CHECK_EQ(zero + zero, zero);
    }

    SUBCASE("1 + 2 = 3") {
        math::bignumbers::BigNumber one("1");
        math::bignumbers::BigNumber two("2");
        math::bignumbers::BigNumber three("3");

        CHECK_EQ(one + two, three);
    }

    SUBCASE("5 + 5 = 10") {
        math::bignumbers::BigNumber five("5");
        math::bignumbers::BigNumber ten("10");
        
        CHECK_EQ(five + five, ten);
    }

    SUBCASE("5 + 15 = 20") {
        math::bignumbers::BigNumber five("5");
        math::bignumbers::BigNumber fifteen("15");
        math::bignumbers::BigNumber twenty("20");

        CHECK_EQ(five + fifteen, twenty);
    }

    SUBCASE("75837483 + 374837472 = 450674955") {
        math::bignumbers::BigNumber num1("75837483");
        math::bignumbers::BigNumber num2("374837472");
        math::bignumbers::BigNumber sum("450674955");

        CHECK_EQ(num1 + num2, sum);
    }
}
