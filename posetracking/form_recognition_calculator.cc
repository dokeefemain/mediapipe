#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <typeinfo>
#include <algorithm>
#include <memory>
#include <array>
//#include <dos.h>
#include "mediapipe/framework/calculator_framework.h"
#include "mediapipe/framework/formats/landmark.pb.h"
#include "mediapipe/framework/formats/rect.pb.h"
#include "mediapipe/framework/input_stream_handler.h"
#include "tensorflow/lite/kernels/register.h"
#include "mediapipe/util/resource_util.h"
#if defined(MEDIAPIPE_ANDROID)
//#include "tensorflow/lite/delegates/nnapi/nnapi_delegate.h"
#endif  // ANDROID
void stringToFile();
std::string feedBack_word;
namespace mediapipe
{

namespace
{
constexpr char normalizedLandmarkListTag[] = "NORM_LANDMARKS";
}
class FormRecognitionCalculator: public CalculatorBase
{
public:
    static ::mediapipe::Status GetContract(CalculatorContract *cc);
    ::mediapipe::Status Open(CalculatorContext *cc) override;

    ::mediapipe::Status Process(CalculatorContext *cc) override;

};

REGISTER_CALCULATOR(FormRecognitionCalculator);

::mediapipe::Status FormRecognitionCalculator::GetContract(
    CalculatorContract *cc)
{
    RET_CHECK(cc->Inputs().HasTag(normalizedLandmarkListTag));
    cc->Inputs().Tag(normalizedLandmarkListTag).Set<mediapipe::NormalizedLandmarkList>();

    if (cc->Outputs().HasTag("FEEDBACK")) {
    cc->Outputs().Tag("FEEDBACK").Set<std::string>();

  }
    return ::mediapipe::OkStatus();
}

::mediapipe::Status FormRecognitionCalculator::Open(
    CalculatorContext *cc)
{
    cc->SetOffset(TimestampDiff(0));
    return ::mediapipe::OkStatus();
}

::mediapipe::Status FormRecognitionCalculator::Process(
    CalculatorContext *cc)
{
    const auto &landmarkList = cc->Inputs()
                                   .Tag(normalizedLandmarkListTag)
                                   .Get<mediapipe::NormalizedLandmarkList>();
    //checking if the user is inframe
    try
    {
        //wrist elbow shoulder hip knee ankle
        float var_x [12] = {landmarkList.landmark(15).x(),landmarkList.landmark(16).x(),landmarkList.landmark(13).x(),landmarkList.landmark(14).x(),landmarkList.landmark(11).x(),landmarkList.landmark(12).x(),landmarkList.landmark(23).x(),landmarkList.landmark(24).x(),landmarkList.landmark(25).x(),landmarkList.landmark(26).x(),landmarkList.landmark(27).x(),landmarkList.landmark(28).x()};
        float var_y [12] = {landmarkList.landmark(15).y(),landmarkList.landmark(16).y(),landmarkList.landmark(13).y(),landmarkList.landmark(14).y(),landmarkList.landmark(11).y(),landmarkList.landmark(12).y(),landmarkList.landmark(23).y(),landmarkList.landmark(24).y(),landmarkList.landmark(25).y(),landmarkList.landmark(26).y(),landmarkList.landmark(27).y(),landmarkList.landmark(28).y()};

    }
    catch (int e)
    {
        LOG(INFO) << "LFT";
        if (cc->Outputs().HasTag("FEEDBACK")) {
    cc->Outputs().Tag("FEEDBACK").AddPacket(
        MakePacket<std::string>("LFT")
            .At(cc->InputTimestamp()));
           }
        return ::mediapipe::OkStatus();
    }

    feedBack_word = "Test";

    if (cc->Outputs().HasTag("FEEDBACK")) {
    cc->Outputs().Tag("FEEDBACK").AddPacket(
        MakePacket<std::string>(feedBack_word)
            .At(cc->InputTimestamp()));
           }
    return ::mediapipe::OkStatus();
    //Add golf form math with output here
}
}