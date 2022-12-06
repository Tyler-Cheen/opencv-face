#include <opencv4/opencv2/opencv.hpp>
#include <vector>


int main()
{
    cv::CascadeClassifier face_detect;
    face_detect.load("/home/tyler/CppProject/face-detect/haarcascade_frontalface_default.xml");
    cv::Scalar color(255,0,0);
    cv::Point org;
    org.x = 100;
    org.y = 100;

    std::vector<cv::Rect> faces; 
    cv::VideoCapture cap(0);
    cv::Mat img;
    while (cap.isOpened() & (char)cv::waitKey(5) != 'q')
    {
        cap.read(img);
        cv::Mat img_gray = img.clone();

        cv::cvtColor(img_gray,img_gray,cv::COLOR_BGR2GRAY);

        face_detect.detectMultiScale(img_gray, faces,1.1 ,3, 0);

        for (auto face: faces)
        {
            // std::cout << face <<std::endl;
            cv::rectangle(img,face,color);
            cv::putText(img,"put q on keyboard to exit!",org,cv::FONT_HERSHEY_COMPLEX,1,color,1,8);
        }

        cv::imshow("video",img);

    }

    cv::destroyAllWindows();

    
    return 0;
}