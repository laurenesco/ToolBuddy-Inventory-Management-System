//
// Program Name:                    qr_search_page.h
// Last Modified:                      04/24/22
// Modified By:                        Lauren Escobedo
// Program Description:            This is the header file for the qr search page. It includes the class definition,
//                                          slot definitions, and included libraries
//

#ifndef QR_SEARCH_H
#define QR_SEARCH_H

#include <QWidget>
#include <QDialog>
#include <QCamera>
#include <QCameraImageCapture>
#include <QMediaRecorder>
#include <QScopedPointer>
#include <QList>
#include <QListWidget>

namespace Ui {
class QR_Search;
}

class QR_Search : public QDialog
{
    Q_OBJECT

public:
    explicit QR_Search(QDialog *parent = nullptr);
    ~QR_Search();
private slots:
    void setCamera(const QCameraInfo &cameraInfo);
    void searchForCamera();

    void startCamera();
    void stopCamera();

    void displayCameraError();

    void closeEvent(QCloseEvent *event) override;
private:
    Ui::QR_Search *ui;

    QScopedPointer<QCamera> m_camera;
    QScopedPointer<QCameraImageCapture> m_imageCapture;
    QScopedPointer<QMediaRecorder> m_mediaRecorder;

    QImageEncoderSettings m_imageSettings;
    QAudioEncoderSettings m_audioSettings;
    QVideoEncoderSettings m_videoSettings;
    QString m_videoContainerFormat;
    bool m_isCapturingImage = false;
    bool m_applicationExiting = false;
};

#endif // QR_SEARCH_H
