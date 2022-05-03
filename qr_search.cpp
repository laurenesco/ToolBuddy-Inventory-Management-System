////
/// Program Name:                qr_search.cpp
/// Last Modified:                  04/24/22
/// Modified By:                     Lauren Escobedo
/// Program Description:       This program is responsible for the functionality of the qr search page.
///                                         This includes connecting to the camera, scanning for new cameras,
///                                         displaying the viewfinder, and utilizing Zebra to scan the qr code.
////

#include "qr_search.h"
#include "ui_qr_search.h"

#include <QMediaService>
#include <QMediaRecorder>
#include <QCameraViewfinder>
#include <QCameraInfo>
#include <QMediaMetaData>

#include <QMessageBox>
#include <QPalette>

#include <QtWidgets>

QR_Search::QR_Search(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::QR_Search)
{
    ui->setupUi(this);
    searchForCamera();
}

QR_Search::~QR_Search()
{
    delete ui;
}

////
///  This function will add available cameras to the camera information display.
///   If none are found it will print "No cameras found."
////
void QR_Search::searchForCamera(){
    QList<QCameraInfo> cameras  = QCameraInfo::availableCameras();
    foreach (const QCameraInfo &cameraInfo, cameras) {
        ui->cameraInfoDisplay->addItem(cameraInfo.deviceName());
    }
    if(ui->cameraInfoDisplay->count() == 0) {
        ui->cameraInfoDisplay->addItem("No cameras found.");
    }
}

void QR_Search::setCamera(const QCameraInfo &cameraInfo)
{
//    m_camera.reset(new QCamera(cameraInfo));
//    connect(m_camera.data(), QOverload<QCamera::Error>::of(&QCamera::error), this, &QR_Search::displayCameraError);
//    m_mediaRecorder.reset(new QMediaRecorder(m_camera.data()));
//    m_mediaRecorder->setMetaData(QMediaMetaData::Title, QVariant(QLatin1String("Test Title")));
//    m_camera->setViewfinder(ui->viewfinder);
//    m_camera->start();
}

void QR_Search::startCamera()
{
    m_camera->start();
}

void QR_Search::stopCamera()
{
    m_camera->stop();
}

void QR_Search::displayCameraError()
{
    QMessageBox::warning(this, tr("Camera Error"), m_camera->errorString());
}

void QR_Search::closeEvent(QCloseEvent *event)
{
    if (m_isCapturingImage) {
        setEnabled(false);
        m_applicationExiting = true;
        event->ignore();
    } else {
        event->accept();
    }
}
