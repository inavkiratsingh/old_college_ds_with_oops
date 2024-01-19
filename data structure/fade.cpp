#include <opencv2/opencv.hpp>
#include <opencv2/face.hpp>

using namespace cv;
using namespace cv::face;

int main() {
    // Load pre-trained face detection and recognition models
    CascadeClassifier faceCascade;
    faceCascade.load("haarcascade_frontalface_default.xml");

    Ptr<FaceRecognizer> faceRecognizer = createEigenFaceRecognizer();
    faceRecognizer->load("eigenface_model.yml");

    // Open the camera
    VideoCapture cap(0); // 0 represents the default camera, you can change it as needed

    if (!cap.isOpened()) {
        std::cerr << "Error opening the camera." << std::endl;
        return -1;
    }

    while (true) {
        Mat frame;
        cap >> frame; // Capture a frame from the camera

        if (frame.empty()) {
            std::cerr << "Error capturing frame." << std::endl;
            break;
        }

        Mat grayFrame;
        cvtColor(frame, grayFrame, COLOR_BGR2GRAY);

        // Detect faces in the frame
        std::vector<Rect> faces;
        faceCascade.detectMultiScale(grayFrame, faces);

        // Iterate through detected faces
        for (const Rect& face : faces) {
            Mat faceROI = grayFrame(face);

            // Perform face recognition
            int label;
            double confidence;

            faceRecognizer->predict(faceROI, label, confidence);

            // Draw a rectangle around the detected face
            rectangle(frame, face, Scalar(0, 255, 0), 2);

            // Display the recognition result
            std::string labelStr = "Person " + std::to_string(label);
            putText(frame, labelStr, Point(face.x, face.y - 10), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 0), 2);

            std::string confidenceStr = "Confidence: " + std::to_string(confidence);
            putText(frame, confidenceStr, Point(face.x, face.y + face.height + 20), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 0), 2);
        }

        // Display the frame
        imshow("Face Recognition", frame);

        // Break the loop if the 'q' key is pressed
        if (waitKey(1) == 'q') {
            break;
        }
    }

    cap.release();
    destroyAllWindows();

    return 0;
}
