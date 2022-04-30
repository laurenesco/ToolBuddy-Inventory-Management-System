//
//Program Name:               qr_search.cpp
//Last Modified:                  04/24/22
//Modified By:                    Lauren Escobedo
//Program Description:      This program is responsible for the functionality of the qr search page.
//                                      This includes connecting to the camera, scanning for new cameras,
//                                      displaying the viewfinder, and utilizing Zebra to scan the qr code.

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

QR_Search::QR_Search(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QR_Search)
{
    ui->setupUi(this);
}

QR_Search::~QR_Search()
{
    delete ui;
}

void QR_Search::setCamera(const QCameraInfo &cameraInfo)
{
    m_camera.reset(new QCamera(cameraInfo));
    connect(m_camera.data(), QOverload<QCamera::Error>::of(&QCamera::error), this, &QR_Search::displayCameraError);
    m_mediaRecorder.reset(new QMediaRecorder(m_camera.data()));
    m_mediaRecorder->setMetaData(QMediaMetaData::Title, QVariant(QLatin1String("Test Title")));
    m_camera->setViewfinder(ui->viewfinder);
    m_camera->start();
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
