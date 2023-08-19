#include "net.h"

#include <algorithm>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<opencv2/opencv.hpp>
#include <stdio.h>
#include <vector>
#include "ZeroDce.h"

//static int detect_zerodec(const cv::Mat& bgr, ncnn::Mat& out)
//{
//    ncnn::Net zerodce;
//
//	zerodce.opt.use_vulkan_compute = true;
//
//	zerodce.load_param("zero-dce_onnx_opt.param");
//	zerodce.load_model("zero-dce_onnx_opt.bin");
//
//    ncnn::Mat in = ncnn::Mat::from_pixels_resize(bgr.data, ncnn::Mat::PIXEL_RGB, bgr.cols, bgr.rows, 512, 512);
//
//    //const float mean_vals[3] = {104.f, 117.f, 123.f};
//	const float mean_vals[3] = {0.f, 0.f, 0.f};
//	const float norm[3] = { 1 / 255.f,  1 / 255.f,  1 / 255.f };
//    in.substract_mean_normalize(mean_vals, norm);
//
//    ncnn::Extractor ex = zerodce.create_extractor();
//
//    ex.input("input.1", in);
//
//    //ncnn::Mat out;
//    ex.extract("79", out);
//	
//	const float out_norm[3] = { 255.f,  255.f,  255.f };
//	out.substract_mean_normalize(mean_vals, out_norm);
//
//    return 0;
//}

void pretty_print(const ncnn::Mat& m)
{
	for (int q = 0; q < m.c; q++)
	{
		const float* ptr = m.channel(q);
		for (int z = 0; z < m.d; z++)
		{
			for (int y = 0; y < m.h; y++)
			{
				for (int x = 0; x < m.w; x++)
				{
					printf("%f ", ptr[x]);
				}
				ptr += m.w;
				printf("\n");
			}
			printf("\n");
		}
		printf("------------------------\n");
	}
}


int main(int argc, char** argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s [imagepath]\n", argv[0]);
		return -1;
	}
	const char* imagepath = argv[1];
	cv::Mat m = cv::imread(imagepath, 1);
    if (m.empty())
    {
        fprintf(stderr, "cv::imread %s failed\n", imagepath);
        return -1;
    }	
	cv::Mat mrgb;
	//cv::resize(m, mresized, cv::Size(512, 512));
	cv::cvtColor(m, mrgb, cv::COLOR_BGR2RGB);
    //std::vector<float> cls_scores;
	ncnn::Mat out;
    //detect_zerodec(mrgb, out);
	ZeroDce* mZeroDce = new ZeroDce();
	mZeroDce->enhance(mrgb, out);    
	//pretty_print(out);
	const char* title = "1";
	//visualize(title, out);
	/*printf("%d ", out.c);
	printf("%d ", out.d);
	printf("%d ", out.h);
	printf("%d ", out.w);*/
	cv::Mat a(out.h, out.w, CV_8UC3);
	out.to_pixels(a.data, ncnn::Mat::PIXEL_RGB2BGR);
	//cv::cvtColor(mrgb, mrgb, cv::COLOR_RGB2BGR);
	cv::imshow(title, a);
	cv::waitKey(0);
    return 0;
}
