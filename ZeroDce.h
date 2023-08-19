#pragma once

#include "net.h"
#include <algorithm>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<opencv2/opencv.hpp>
#include <stdio.h>
#include <vector>

class ZeroDce
{
public: 
	ZeroDce();
	int enhance(cv::Mat& input_img, ncnn::Mat& out);

private:
	ncnn::Net zerodce;
	const float mean_vals[3] = { 0.f, 0.f, 0.f };
	const float norm[3] = { 1 / 255.f,  1 / 255.f,  1 / 255.f };
	const float out_norm[3] = { 255.f,  255.f,  255.f };
};

