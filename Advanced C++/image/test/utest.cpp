#include "mu_test.h"
#include "image.hpp"
#include <fstream>

bool cctor(cpp::Image<uint_fast16_t> a_image)
{
	return a_image.getPixel(1,1) == 80 
		&& a_image.getPixel(2,2) == 70 ;
}

BEGIN_TEST(copy_and_cctor)

	cpp::Image<uint_fast16_t> image(4,4,"P2",255);
	image.setPixel(1,1, 80);
	image.setPixel(2,2, 70);

	cpp::Image<uint_fast16_t> copy;
	copy = image;

    ASSERT_EQUAL(copy.getPixel(1,1), image.getPixel(1,1));
	ASSERT_EQUAL(copy.getPixel(2,2), image.getPixel(2,2));
	ASSERT_EQUAL(cctor(image),true);

END_TEST

cpp::Image<uint_fast16_t> generate()
{
	cpp::Image<uint_fast16_t> temp(4,4,"P2",255);
	temp.setPixel(1,1, 80);
	temp.setPixel(2,2, 70);
	return temp;
}

cpp::Image<uint_fast16_t> Transform(cpp::Image<uint_fast16_t> a_image)
{
	return a_image;
}

BEGIN_TEST(move_copy_and_cctor)

	cpp::Image<uint_fast16_t> image;
	image = generate();
    ASSERT_EQUAL(image.getPixel(1,1),80);
	ASSERT_EQUAL(image.getPixel(2,2), 70);

	ASSERT_EQUAL(Transform(generate()).getPixel(1,1),80);
	ASSERT_EQUAL(Transform(generate()).getPixel(2,2), 70);

END_TEST

BEGIN_TEST(brighten)

	std::ifstream cat("../data/cat.pgm");
	cpp::Image<uint_fast16_t> image = cpp::read<uint_fast16_t>(cat);

	cpp::Image<uint_fast16_t> brightenImage = brighten(image, 50);

	std::ofstream brightenCat("../data/brightenCat.pgm");
	cpp::save<uint_fast16_t>(brightenImage, brightenCat);

	ASSERT_PASS();

END_TEST

BEGIN_TEST(change_color_scale)

	std::ifstream cat("../data/cat.pgm");
	cpp::Image<uint_fast16_t> image = cpp::read<uint_fast16_t>(cat);

	cpp::Image<uint_fast16_t> changeColorScaleImage = changeColorScale(image, (uint_fast16_t)4);
	std::ofstream changeColorScaleCat("../data/changeColorScaleCat.pgm");
	cpp::save (changeColorScaleImage, changeColorScaleCat);

	ASSERT_PASS();

END_TEST

BEGIN_TEST(pixelate)

	std::ifstream cat("../data/cat.pgm");
	cpp::Image<uint_fast16_t> image = cpp::read<uint_fast16_t>(cat);

	cpp::Image<uint_fast16_t> pixelateImage = pixelate(image);
	std::ofstream pixelateCat("../data/pixelateCat.pgm");
	cpp::save (pixelateImage, pixelateCat);

	ASSERT_PASS();

END_TEST

BEGIN_SUITE(TEST)

	TEST(copy_and_cctor)
	TEST(move_copy_and_cctor)
	TEST(brighten)
	TEST(change_color_scale)
	TEST(pixelate)

END_SUITE
