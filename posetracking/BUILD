cc_library(
    name = "string_to_render_data_calculator",
    srcs = ["string_to_render_data_calculator.cc"],
    visibility = ["//visibility:public"],
    deps =[
        "//mediapipe/framework:calculator_framework",
        "//mediapipe/framework/port:ret_check",
        "//mediapipe/util:render_data_cc_proto",
        "@com_google_absl//absl/memory",
    ],
    alwayslink = 1,
)

cc_library(
    name = "form_recognition_calculator",
    srcs = ["form_recognition_calculator.cc"],
    visibility = ["//visibility:public"],
    deps = [
        "//mediapipe/framework:calculator_framework",
        "//mediapipe/framework/formats:landmark_cc_proto",
        "//mediapipe/framework/port:status",
        "//mediapipe/framework/formats:rect_cc_proto",
        "//mediapipe/framework/port:ret_check",
        "//mediapipe/util:resource_util",
        "@org_tensorflow//tensorflow/lite/kernels:builtin_ops",

        ]+ select({
        "//conditions:default": [
            "@org_tensorflow//tensorflow/core:framework",
        ],
        "//mediapipe:android": [
            "@org_tensorflow//tensorflow/core:portable_tensorflow_lib_lite",
        ],
        "//mediapipe:macos": [
            "//mediapipe/framework/port:file_helpers",
        ],

    }),

    alwayslink = 1,
)