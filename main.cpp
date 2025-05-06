
// #include <iostream>

// int main() {
//     std::cout << "Hello, CMake World!" << std::endl;
//     return 0;
// }
// #include <dlib/matrix.h>
// #include <iostream>

// // int main() {
// //     dlib::matrix<double, 2, 2> m;
// //     m = 1, 2,
// //         3, 4;
// //     std::cout << m << std::endl;
// //     return 0;
// // }

// #include <iostream>
// int main() {
//     std::cout << "Hello, CMake World!" << std::endl;
//     return 0;
// }

// #include <D:/MyEventMemory/New_server/new_server/face_recognition_module/dlib/dlib-master/dlib/image_processing/frontal_face_detector.h>
// #include <D:/MyEventMemory/New_server/new_server/face_recognition_module/dlib/dlib-master/dlib/image_io.h>
// #include <iostream>

// int main() {
//     try {
//         dlib::frontal_face_detector detector = dlib::get_frontal_face_detector();
//         std::cout << "Dlib is working and face detector created!" << std::endl;
//     } catch (std::exception& e) {
//         std::cerr << "Error: " << e.what() << std::endl;
//     }
//     return 0;
// }











#include <D:/MyEventMemory/New_server/new_server/face_recognition_module/dlib/dlib-master/dlib/image_processing/frontal_face_detector.h>
#include <D:/MyEventMemory/New_server/new_server/face_recognition_module/dlib/dlib-master/dlib/image_io.h>
#include <iostream>
#include <D:/MyEventMemory/New_server/new_server/face_recognition_module/dlib/dlib-master/dlib/dnn.h>
#include <D:/MyEventMemory/New_server/new_server/face_recognition_module/dlib/dlib-master/dlib/image_processing.h>
#include <cstddef>

// הגדרת מבנה הרשת לזיהוי פנים (resnet)
template <template <int, template<typename> class, int, typename> class block,
          int N, template<typename> class BN, typename SUBNET>
using residual = dlib::add_prev1<block<N, BN, 1, dlib::tag1<SUBNET>>>;

template <template <int, template<typename> class, int, typename> class block,
          int N, template<typename> class BN, typename SUBNET>
using residual_down = dlib::add_prev2<dlib::avg_pool<2,2,2,2,
                       dlib::skip1<block<N, BN, 2,
                       dlib::tag1<SUBNET>>>>>;

template <int N, template <typename> class BN, int stride, typename SUBNET>
using block  = BN<dlib::con<N,3,3,1,1,
                dlib::relu<BN<dlib::con<N,3,3,stride,stride,SUBNET>>>>>;

template <int N, typename SUBNET> using ares      = residual<block,N,dlib::bn_con,SUBNET>;
template <int N, typename SUBNET> using ares_down = residual_down<block,N,dlib::bn_con,SUBNET>;

using anet_type = dlib::loss_metric<dlib::fc_no_bias<128,
                    dlib::avg_pool_everything<
                    ares<256,ares<256,ares_down<256,
                    ares<128,ares<128,ares_down<128,
                    ares<64,ares<64,ares<64,
                    dlib::max_pool<3,3,2,2,
                    dlib::relu<dlib::bn_con<dlib::con<64,7,7,2,2,
                    dlib::input_rgb_image_sized<150>
                    >>>>>>>>>>>>>>>>;


// int main() {
//     try {
//         dlib::frontal_face_detector detector = dlib::get_frontal_face_detector();
//         std::cout << "Dlib is working and face detector created!" << std::endl;
//     } catch (std::exception& e) {
//         std::cerr << "Error: " << e.what() << std::endl;
//     }
//     return 0;
// }
int main() {
    try {
        dlib::frontal_face_detector detector = dlib::get_frontal_face_detector();
        std::cout << "Dlib is working and face detector created!" << std::endl;

        // טען את מודל ה-ResNet לזיהוי פנים
        anet_type net;
        dlib::deserialize("D:/MyEventMemory/New_server/new_server/face_recognition_module/models/dlib_face_recognition_resnet_model_v1.dat") >> net;
        std::cout << "ResNet model loaded successfully!" << std::endl;

    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}














// #include <iostream>
// #include <fstream>
// #include <dlib/dnn.h>
// #include <dlib/image_processing/frontal_face_detector.h>

// using namespace dlib;
// using namespace std;

// // הגדרה של רשת כמו ב-dlib
// template <template <int, template <typename> class, int, typename> class block,
//           int N, template <typename> class BN, typename SUBNET>
// using residual = add_prev1<block<N, BN, 1, tag1<SUBNET>>>;

// template <int N, template <typename> class BN, int stride, typename SUBNET>
// using block = BN<con<N, 3, 3, stride, stride, relu<BN<con<N, 3, 3, 1, 1, SUBNET>>>>>;

// template <typename SUBNET> using res = relu<residual<block, 256, bn_con, SUBNET>>;
// using net_type = loss_metric<fc_no_bias<128, avg_pool_everything<res<avg_pool<2,2,2,2,relu<bn_con<con<64,7,7,2,2,input_rgb_image_sized<150>>>>>>>>;

// int main()
// {
//     const std::string model_path = "models/dlib_face_recognition_resnet_model_v1.dat";

//     // בדיקה אם הקובץ קיים
//     std::ifstream file(model_path);
//     if (!file)
//     {
//         std::cerr << "Error: model file not found at path: " << model_path << std::endl;
//         return 1;
//     }
//     file.close();

//     try
//     {
//         net_type net;
//         deserialize(model_path) >> net;
//         std::cout << "Model loaded successfully!" << std::endl;
//     }
//     catch (std::exception& e)
//     {
//         std::cerr << "Error loading model: " << e.what() << std::endl;
//         return 1;
//     }

//     return 0;
// }
