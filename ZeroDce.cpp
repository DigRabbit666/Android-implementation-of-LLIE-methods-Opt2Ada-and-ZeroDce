#include "ZeroDce.h"

ZeroDce::ZeroDce()
{
	zerodce.opt.use_vulkan_compute = true;	
	zerodce.load_param("zero-dce_onnx_opt.param");
	zerodce.load_model("zero-dce_onnx_opt.bin");
}

int ZeroDce::enhance(cv::Mat& bgr, ncnn::Mat& out)
{
	ncnn::Mat in = ncnn::Mat::from_pixels_resize(bgr.data, ncnn::Mat::PIXEL_RGB, bgr.cols, bgr.rows, 512, 512);
	in.substract_mean_normalize(mean_vals, norm);
	ncnn::Extractor ex = zerodce.create_extractor();
	ex.input("input.1", in);
	//ncnn::Mat out;
	ex.extract("79", out);	
	out.substract_mean_normalize(mean_vals, out_norm);
	//cv::Mat a(out.h, out.w, CV_8UC3);
	//out.to_pixels(bgr.data, ncnn::Mat::PIXEL_RGB);
	return 0;
}
