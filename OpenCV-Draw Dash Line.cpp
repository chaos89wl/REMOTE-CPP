#include <opencv2/opencv.hpp>

void drawDashedLine(cv::Mat& img, cv::Point pt1, cv::Point pt2, const cv::Scalar& color, int thickness = 1, int lineType = cv::LINE_8, int dashLength = 5)
{
    // Calculate the total length of the line
    double lineLength = cv::norm(pt1 - pt2);

    // Calculate the number of dashes
    int numDashes = static_cast<int>(lineLength / dashLength);

    // Calculate the direction vector of the line
    cv::Point2f direction = (pt2 - pt1) / lineLength;

    for (int i = 0; i < numDashes; ++i)
    {
        // Calculate the start and end points of each dash
        cv::Point2f start = pt1 + direction * (i * dashLength);
        cv::Point2f end = pt1 + direction * ((i + 0.5) * dashLength);

        // Draw the dash
        cv::line(img, start, end, color, thickness, lineType);
    }
}

int main()
{
    // 400x400 크기의 검은색 이미지 생성
    cv::Mat img = cv::Mat::zeros(400, 400, CV_8UC3);

    // 점선의 시작점과 끝점 설정
    cv::Point pt1(50, 50);
    cv::Point pt2(350, 350);

    // 점선의 색상 (파란색), 두께 (2)
    cv::Scalar color(255, 0, 0);
    int thickness = 2;

    // 이미지에 점선 그리기
    drawDashedLine(img, pt1, pt2, color, thickness);

    // 결과 이미지 표시
    cv::imshow("Dashed Line", img);
    cv::waitKey(0);

    return 0;
}