#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QLabel>
#include <QTextBlock>
#include "Participant.h"
#include "sharedmemory.h"
#include <stdio.h>
#include <conio.h>
#include <QTimer>
#include <QImage>
#include <QtMath>

#include <Windows.h>
#include "trackborders.h"

#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QSerialPort>

#define MAP_OBJECT_NAME "$pcars$"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void runningCheckedChanged(int newState);
    void update();

private:
    Ui::MainWindow *ui;

    void refreshView();
    QString getGameStateString(int gameState);
    QString getSessionStateString(int sessionState);
    bool isFriend(QString playerName);
    void drawMap();
    void setPx(int x, int y, int colorCode);
    void clearBoolArray();

    wchar_t *convertCharArrayToLPCWSTR(const char* charArray);

    QTimer *timer;

    int* m_xCircle;
    int* m_yCircle;
    int circleSize;
    bool* m_map;

    QString m_currentTrack;
    float m_minX;
    float m_maxX;
    float m_minY;
    float m_maxY;
    float m_minZ;
    float m_maxZ;

    float lastLapTime;
    float fuelUsedLastLap;
    float fuelAmountBeginLap;

    QImage m_image;

    QList<QLabel*> m_labelsPos;
    QList<QLabel*> m_labelsName;
    QList<QLabel*> m_labelsCar;
    QList<Participant*> m_participants;

    QList<QWidget*> m_backgrWidgets;
    QList<QWidget*> m_lineSeps;

    HANDLE fileHandle;
    SharedMemory *sharedData;
    QList<QSerialPortInfo> m_ports;
    QSerialPort m_port;

    bool arduinoConnected;

private slots:
    void on_comboBox_currentIndexChanged(int index);

};

#endif // MAINWINDOW_H
