#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "util.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //UtilH::hure(3);

    fuelAmountBeginLap = 0.0;
    fuelUsedLastLap = 0.0;
    lastLapTime = 0.0;

    fileHandle = NULL;
    m_map = new bool[512*1024];
    for (int i = 0; i < 512*1024; i++)
    {
        m_map[i] = false;
    }

    m_xCircle = new int[81 + 81 + 15] {-2, -1, 0, 1, 2, -4, -3, -2, -1, 0, 1, 2, 3, 4, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, //81
                            -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, //15
                            -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, -4, -3, -2, -1, 0, 1, 2, 3, 4, -2, -1, 0, 1, 2};
    m_yCircle = new int[81 + 81 + 15] {7, 7, 7, 7, 7, 6, 6, 6, 6, 6, 6, 6, 6, 6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -6, -6, -6, -6, -6, -6, -6, -6, -6, -7, -7, -7, -7, -7};
    circleSize = 81 + 81 + 15;


    m_currentTrack = "";
    m_minX = -1;
    m_maxX = 1;
    m_minY = -1;
    m_maxY = 1;
    m_minZ = -1;
    m_maxZ = 1;

    m_image = QImage(QSize(1024, 512), QImage::Format_RGB32);


    QLabel* labelImage = ui->label_Image;
    labelImage->setPixmap(QPixmap::fromImage(m_image));


    QRgb val;
    val = qRgb(189, 149, 39);

    for (int x = 0; x < 1024; x++)
    {
        for (int y = 0; y < 512; y++)
        {
            setPx(x, y, 0);
        }
    }
    labelImage->setPixmap(QPixmap::fromImage(m_image));



    m_labelsPos.append(ui->label_1_Pos);
    m_labelsPos.append(ui->label_2_Pos);
    m_labelsPos.append(ui->label_3_Pos);
    m_labelsPos.append(ui->label_4_Pos);
    m_labelsPos.append(ui->label_5_Pos);
    m_labelsPos.append(ui->label_6_Pos);
    m_labelsPos.append(ui->label_7_Pos);
    m_labelsPos.append(ui->label_8_Pos);
    m_labelsPos.append(ui->label_9_Pos);
    m_labelsPos.append(ui->label_10_Pos);
    m_labelsPos.append(ui->label_11_Pos);
    m_labelsPos.append(ui->label_12_Pos);
    m_labelsPos.append(ui->label_13_Pos);
    m_labelsPos.append(ui->label_14_Pos);
    m_labelsPos.append(ui->label_15_Pos);
    m_labelsPos.append(ui->label_16_Pos);
    m_labelsPos.append(ui->label_17_Pos);
    m_labelsPos.append(ui->label_18_Pos);
    m_labelsPos.append(ui->label_19_Pos);
    m_labelsPos.append(ui->label_20_Pos);
    m_labelsPos.append(ui->label_21_Pos);
    m_labelsPos.append(ui->label_22_Pos);
    m_labelsPos.append(ui->label_23_Pos);
    m_labelsPos.append(ui->label_24_Pos);
    m_labelsPos.append(ui->label_25_Pos);
    m_labelsPos.append(ui->label_26_Pos);
    m_labelsPos.append(ui->label_27_Pos);
    m_labelsPos.append(ui->label_28_Pos);
    m_labelsPos.append(ui->label_29_Pos);
    m_labelsPos.append(ui->label_30_Pos);
    m_labelsPos.append(ui->label_31_Pos);
    m_labelsPos.append(ui->label_32_Pos);

    m_labelsName.append(ui->label_1_Name);
    m_labelsName.append(ui->label_2_Name);
    m_labelsName.append(ui->label_3_Name);
    m_labelsName.append(ui->label_4_Name);
    m_labelsName.append(ui->label_5_Name);
    m_labelsName.append(ui->label_6_Name);
    m_labelsName.append(ui->label_7_Name);
    m_labelsName.append(ui->label_8_Name);
    m_labelsName.append(ui->label_9_Name);
    m_labelsName.append(ui->label_10_Name);
    m_labelsName.append(ui->label_11_Name);
    m_labelsName.append(ui->label_12_Name);
    m_labelsName.append(ui->label_13_Name);
    m_labelsName.append(ui->label_14_Name);
    m_labelsName.append(ui->label_15_Name);
    m_labelsName.append(ui->label_16_Name);
    m_labelsName.append(ui->label_17_Name);
    m_labelsName.append(ui->label_18_Name);
    m_labelsName.append(ui->label_19_Name);
    m_labelsName.append(ui->label_20_Name);
    m_labelsName.append(ui->label_21_Name);
    m_labelsName.append(ui->label_22_Name);
    m_labelsName.append(ui->label_23_Name);
    m_labelsName.append(ui->label_24_Name);
    m_labelsName.append(ui->label_25_Name);
    m_labelsName.append(ui->label_26_Name);
    m_labelsName.append(ui->label_27_Name);
    m_labelsName.append(ui->label_28_Name);
    m_labelsName.append(ui->label_29_Name);
    m_labelsName.append(ui->label_30_Name);
    m_labelsName.append(ui->label_31_Name);
    m_labelsName.append(ui->label_32_Name);

    m_labelsCar.append(ui->label_1_Car);
    m_labelsCar.append(ui->label_2_Car);
    m_labelsCar.append(ui->label_3_Car);
    m_labelsCar.append(ui->label_4_Car);
    m_labelsCar.append(ui->label_5_Car);
    m_labelsCar.append(ui->label_6_Car);
    m_labelsCar.append(ui->label_7_Car);
    m_labelsCar.append(ui->label_8_Car);
    m_labelsCar.append(ui->label_9_Car);
    m_labelsCar.append(ui->label_10_Car);
    m_labelsCar.append(ui->label_11_Car);
    m_labelsCar.append(ui->label_12_Car);
    m_labelsCar.append(ui->label_13_Car);
    m_labelsCar.append(ui->label_14_Car);
    m_labelsCar.append(ui->label_15_Car);
    m_labelsCar.append(ui->label_16_Car);
    m_labelsCar.append(ui->label_17_Car);
    m_labelsCar.append(ui->label_18_Car);
    m_labelsCar.append(ui->label_19_Car);
    m_labelsCar.append(ui->label_20_Car);
    m_labelsCar.append(ui->label_21_Car);
    m_labelsCar.append(ui->label_22_Car);
    m_labelsCar.append(ui->label_23_Car);
    m_labelsCar.append(ui->label_24_Car);
    m_labelsCar.append(ui->label_25_Car);
    m_labelsCar.append(ui->label_26_Car);
    m_labelsCar.append(ui->label_27_Car);
    m_labelsCar.append(ui->label_28_Car);
    m_labelsCar.append(ui->label_29_Car);
    m_labelsCar.append(ui->label_30_Car);
    m_labelsCar.append(ui->label_31_Car);
    m_labelsCar.append(ui->label_32_Car);

    m_backgrWidgets.append(ui->horizontalWidget_Pos_1);
    m_backgrWidgets.append(ui->horizontalWidget_Pos_2);
    m_backgrWidgets.append(ui->horizontalWidget_Pos_3);
    m_backgrWidgets.append(ui->horizontalWidget_Pos_4);
    m_backgrWidgets.append(ui->horizontalWidget_Pos_5);
    m_backgrWidgets.append(ui->horizontalWidget_Pos_6);
    m_backgrWidgets.append(ui->horizontalWidget_Pos_7);
    m_backgrWidgets.append(ui->horizontalWidget_Pos_8);
    m_backgrWidgets.append(ui->horizontalWidget_Pos_9);
    m_backgrWidgets.append(ui->horizontalWidget_Pos_10);
    m_backgrWidgets.append(ui->horizontalWidget_Pos_11);
    m_backgrWidgets.append(ui->horizontalWidget_Pos_12);
    m_backgrWidgets.append(ui->horizontalWidget_Pos_13);
    m_backgrWidgets.append(ui->horizontalWidget_Pos_14);
    m_backgrWidgets.append(ui->horizontalWidget_Pos_15);
    m_backgrWidgets.append(ui->horizontalWidget_Pos_16);
    m_backgrWidgets.append(ui->horizontalWidget_Pos_17);
    m_backgrWidgets.append(ui->horizontalWidget_Pos_18);
    m_backgrWidgets.append(ui->horizontalWidget_Pos_19);
    m_backgrWidgets.append(ui->horizontalWidget_Pos_20);
    m_backgrWidgets.append(ui->horizontalWidget_Pos_21);
    m_backgrWidgets.append(ui->horizontalWidget_Pos_22);
    m_backgrWidgets.append(ui->horizontalWidget_Pos_23);
    m_backgrWidgets.append(ui->horizontalWidget_Pos_24);
    m_backgrWidgets.append(ui->horizontalWidget_Pos_25);
    m_backgrWidgets.append(ui->horizontalWidget_Pos_26);
    m_backgrWidgets.append(ui->horizontalWidget_Pos_27);
    m_backgrWidgets.append(ui->horizontalWidget_Pos_28);
    m_backgrWidgets.append(ui->horizontalWidget_Pos_29);
    m_backgrWidgets.append(ui->horizontalWidget_Pos_30);
    m_backgrWidgets.append(ui->horizontalWidget_Pos_31);
    m_backgrWidgets.append(ui->horizontalWidget_Pos_32);

    m_lineSeps.append(ui->line_P1);
    m_lineSeps.append(ui->line_P2);
    m_lineSeps.append(ui->line_P3);
    m_lineSeps.append(ui->line_P4);
    m_lineSeps.append(ui->line_P5);
    m_lineSeps.append(ui->line_P6);
    m_lineSeps.append(ui->line_P7);
    m_lineSeps.append(ui->line_P8);
    m_lineSeps.append(ui->line_P9);
    m_lineSeps.append(ui->line_P10);
    m_lineSeps.append(ui->line_P11);
    m_lineSeps.append(ui->line_P12);
    m_lineSeps.append(ui->line_P13);
    m_lineSeps.append(ui->line_P14);
    m_lineSeps.append(ui->line_P15);
    m_lineSeps.append(ui->line_P16);
    m_lineSeps.append(ui->line_P17);
    m_lineSeps.append(ui->line_P18);
    m_lineSeps.append(ui->line_P19);
    m_lineSeps.append(ui->line_P20);
    m_lineSeps.append(ui->line_P21);
    m_lineSeps.append(ui->line_P22);
    m_lineSeps.append(ui->line_P23);
    m_lineSeps.append(ui->line_P24);
    m_lineSeps.append(ui->line_P25);
    m_lineSeps.append(ui->line_P26);
    m_lineSeps.append(ui->line_P27);
    m_lineSeps.append(ui->line_P28);
    m_lineSeps.append(ui->line_P29);
    m_lineSeps.append(ui->line_P30);
    m_lineSeps.append(ui->line_P31);

    ui->comboBoxColorOwn->addItem("Yellow");
    ui->comboBoxColorOwn->addItem("Green");
    ui->comboBoxColorOwn->addItem("Blue");
    ui->comboBoxColorOwn->addItem("Red");
    ui->comboBoxColorOwn->addItem("Orange");

    ui->comboBoxColorFriends->addItem("Yellow");
    ui->comboBoxColorFriends->addItem("Green");
    ui->comboBoxColorFriends->addItem("Blue");
    ui->comboBoxColorFriends->addItem("Red");
    ui->comboBoxColorFriends->addItem("Orange");

    Participant *part1 = new Participant();
    part1->setPosition(1);
    part1->setName("Sapp");
    part1->setCar("  McLaren");
    m_participants.append(part1);
    Participant *part2 = new Participant();
    part2->setPosition(2);
    part2->setName("Asssasssiino");
    part2->setCar("  Ford Mustang");
    m_participants.append(part2);
    Participant *part3 = new Participant();
    part3->setPosition(3);
    part3->setName("Mason");
    part3->setCar("  Audi R8");
    m_participants.append(part3);

    m_backgrWidgets.at(0)->setStyleSheet("background-color:yellow;");

    connect(ui->checkBoxRunning, SIGNAL(stateChanged(int)), this, SLOT(runningCheckedChanged(int)));

    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(update()));

    refreshView();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update()
{
    ui->label_Info_GameState->setText(getGameStateString(sharedData->mGameState));
    ui->label_Info_SessionState->setText(getSessionStateString(sharedData->mSessionState));

    //ui->textEdit_FriendsNames->setText(QString(sharedData->mTrackLocation) + "\n" + QString(sharedData->mTrackVariation) + "\n");


    // Remaining Time

    float remainingTimemMili = sharedData->mEventTimeRemaining;
    int minutes = (int)(remainingTimemMili / (1000.0 * 60.0));
    int seconds = ((int)(remainingTimemMili / (1000.0))) % 60;

    ui->label_remaining_time->setText(QString::number(sharedData->mEventTimeRemaining) + ":" + QString::number(seconds));




    // Fuel consumption

    if (qFabs(lastLapTime - sharedData->mCurrentTime) > 10.0 && sharedData->mSpeed > 3.0)
    {
        float nowFuel = sharedData->mFuelCapacity * sharedData->mFuelLevel;
        fuelUsedLastLap = fuelAmountBeginLap - nowFuel;
        fuelAmountBeginLap = nowFuel;

        ui->label_average_fuel->setText(QString::number(fuelUsedLastLap));
    }
    lastLapTime = sharedData->mCurrentTime;

    //ui->label_remaining_time->setText(QString::number(sharedData->mFuelCapacity * sharedData->mFuelLevel) + ":" + QString::number(sharedData->mCurrentTime));


    // Laps amount

    unsigned int lapsAmount = sharedData->mLapsInEvent;

    ui->label_laps_amount->setText(QString::number(lapsAmount) + " (Fuel: " + QString::number(lapsAmount * fuelUsedLastLap) +")");



    // Damage

    int damageAero = (int)(sharedData->mAeroDamage * 100.0);
    int damageEngine = (int)(sharedData->mEngineDamage * 100.0);
    ui->label_damage_aero->setText("Aerodamage: " + QString::number(damageAero));
    ui->label_damage_engine->setText("Enginedamage: " + QString::number(damageEngine));








    int particAmount = sharedData->mNumParticipants;
    //ui->label_debug->setText("Paricipants amount: " + QString::number(particAmount));

    if (particAmount != m_participants.size())
    {

        for (int i = 0; i < m_participants.size(); i++)
        {
            delete(m_participants.at(i));
        }

        m_participants.clear();

        for (int i = 0; i < particAmount; i++)
        {
            Participant *part = new Participant();
            part->setPosition(sharedData->mParticipantInfo[i].mRacePosition);
            part->setName(QString(sharedData->mParticipantInfo[i].mName));
            part->setCar("");
            part->setWorldPosition(sharedData->mParticipantInfo[i].mWorldPosition[0], sharedData->mParticipantInfo[i].mWorldPosition[1], sharedData->mParticipantInfo[i].mWorldPosition[2]);

            m_participants.append(part);
        }

    }
    else
    {
        for (int i = 0; i < particAmount; i++)
        {
            if (m_participants.at(i)->getName() == sharedData->mParticipantInfo[i].mName)
            {
                m_participants.at(i)->setPosition(sharedData->mParticipantInfo[i].mRacePosition);
                m_participants.at(i)->setWorldPosition(sharedData->mParticipantInfo[i].mWorldPosition[0], sharedData->mParticipantInfo[i].mWorldPosition[1], sharedData->mParticipantInfo[i].mWorldPosition[2]);
            }
            else
            {
                for (int j = 0; j < particAmount; j++)
                {
                    if (m_participants.at(i)->getName() == sharedData->mParticipantInfo[j].mName)
                    {
                        m_participants.at(i)->setPosition(sharedData->mParticipantInfo[j].mRacePosition);
                        m_participants.at(i)->setWorldPosition(sharedData->mParticipantInfo[j].mWorldPosition[0], sharedData->mParticipantInfo[j].mWorldPosition[1], sharedData->mParticipantInfo[j].mWorldPosition[2]);
                    }
                }
            }

            bool swhereIn = false;
            if (m_participants.at(i)->getWorldPositionX() > m_maxX)
            {
                m_maxX = m_participants.at(i)->getWorldPositionX() + 35;
                swhereIn = true;
            }
            if (m_participants.at(i)->getWorldPositionX() < m_minX)
            {
                m_minX = m_participants.at(i)->getWorldPositionX() - 35;
                swhereIn = true;
            }
            if (m_participants.at(i)->getWorldPositionY() > m_maxY)
            {
                m_maxY = m_participants.at(i)->getWorldPositionY() + 35;
                swhereIn = true;
            }
            if (m_participants.at(i)->getWorldPositionY() < m_minY)
            {
                m_minY = m_participants.at(i)->getWorldPositionY() - 35;
                swhereIn = true;
            }
            if (m_participants.at(i)->getWorldPositionZ() > m_maxZ)
            {
                m_maxZ = m_participants.at(i)->getWorldPositionZ() + 35;
                swhereIn = true;
            }
            if (m_participants.at(i)->getWorldPositionZ() < m_minZ)
            {
                m_minZ = m_participants.at(i)->getWorldPositionZ() - 35;
                swhereIn = true;
            }

            if (swhereIn)
            {
                clearBoolArray();
            }


            int xPos = 1024 - ((int)((m_participants.at(i)->getWorldPositionX() - m_minX) / (m_maxX - m_minX) * 1024));
            int yPos = (int)((m_participants.at(i)->getWorldPositionZ() - m_minZ) / (m_maxZ - m_minZ) * 512);
            xPos = xPos < 0 ? 0 : (xPos >= 1024 ? 1024 : xPos);
            yPos = yPos < 0 ? 0 : (yPos >= 512 ? 512 : yPos);
            m_map[xPos + yPos * 1024] = true;

        }
    }

    ui->label_MinMax->setText("," + QString(sharedData->mTrackLocation) + "," + QString(sharedData->mTrackVariation) + ", X=[" + QString::number(m_minX) + "," + QString::number(m_maxX) + "], Y=[" + QString::number(m_minY) + "," + QString::number(m_maxY) + "], Z=[" + QString::number(m_minZ) + "," + QString::number(m_maxZ) + "]");

    if (m_currentTrack != QString(sharedData->mTrackLocation) + "," + QString(sharedData->mTrackVariation))
    {
        m_currentTrack = QString(sharedData->mTrackLocation) + "," + QString(sharedData->mTrackVariation);
        //int* borders = TrackBorders::getBorders(QString(sharedData->mTrackLocation), QString(sharedData->mTrackVariation));
        /*m_minX = TrackBorders::getBorderMinX(QString(sharedData->mTrackLocation), QString(sharedData->mTrackVariation));
        m_maxX = TrackBorders::getBorderMaxX(QString(sharedData->mTrackLocation), QString(sharedData->mTrackVariation));
        m_minZ = TrackBorders::getBorderMinZ(QString(sharedData->mTrackLocation), QString(sharedData->mTrackVariation));
        m_maxZ = TrackBorders::getBorderMaxZ(QString(sharedData->mTrackLocation), QString(sharedData->mTrackVariation));*/

        QRgb val;
        val = qRgb(189, 149, 39);

        for (int x = 0; x < 1024; x++)
        {
            for (int y = 0; y < 512; y++)
            {
                //m_image.setPixel(x, y, val);
            }
        }
    }


    drawMap();

    ui->label_Image->setPixmap(QPixmap::fromImage(m_image));


    refreshView();
}

void MainWindow::drawMap()
{
   // QRgb val;
    //val = qRgb(0, 0, 0);
    //m_image.setPixel(1024 - ((int)((m_participants.at(i)->getWorldPositionX() - m_minX) / (m_maxX - m_minX) * 1024)),
     //                (int)((m_participants.at(i)->getWorldPositionZ() - m_minZ) / (m_maxZ - m_minZ) * 512), val);

    for (int i = 0; i < m_participants.size(); i++)
    {
        int xPosOld = 1024 - ((int)((m_participants.at(i)->getOldWorldPositionX() - m_minX) / (m_maxX - m_minX) * 1024));
        int yPosOld = (int)((m_participants.at(i)->getOldWorldPositionZ() - m_minZ) / (m_maxZ - m_minZ) * 512);
        int xPos = 1024 - ((int)((m_participants.at(i)->getWorldPositionX() - m_minX) / (m_maxX - m_minX) * 1024));
        int yPos = (int)((m_participants.at(i)->getWorldPositionZ() - m_minZ) / (m_maxZ - m_minZ) * 512);

        for (int j = 0; j < circleSize; j++)
        {
            if (m_xCircle[j] + xPosOld + (m_yCircle[j] + yPosOld)*1024 >= 0 && m_xCircle[j] + xPosOld + (m_yCircle[j] + yPosOld)*1024 < 1024*512)
            {
                if (m_map[m_xCircle[j] + xPosOld + (m_yCircle[j] + yPosOld)*1024])
                {
                    setPx(m_xCircle[j] + xPosOld, m_yCircle[j] + yPosOld, 2);
                }
                else
                {
                    setPx(m_xCircle[j] + xPosOld, m_yCircle[j] + yPosOld, 0);
                }
            }
        }


        for (int j = 0; j < circleSize; j++)
        {
            if (isFriend(m_participants.at(i)->getName()))
            {
                setPx(m_xCircle[j] + xPos, m_yCircle[j] + yPos, 4);
            }
            else if (m_participants.at(i)->getName() == ui->lineEdit_ownName->text())
            {
                setPx(m_xCircle[j] + xPos, m_yCircle[j] + yPos, 3);
            }
            else
            {
                setPx(m_xCircle[j] + xPos, m_yCircle[j] + yPos, 1);
            }
        }
    }
}

void MainWindow::setPx(int x, int y, int colorCode)
{
    QRgb val;
    switch (colorCode)
    {
    case 0:
        val = qRgb(160, 160, 160);
        break;
    case 1:
        val = qRgb(205, 205, 205);
        break;
    case 2:
        val = qRgb(0, 0, 0);
        break;
    case 3:
        val = qRgb(0, 0, 255);
        break;
    case 4:
        val = qRgb(218, 165, 32);
        break;
    default:
        val = qRgb(0, 0, 0);
    }

    x = x < 0 ? 0 : (x >= 1024 ? 1023 : x);
    y = y < 0 ? 0 : (y >= 512 ? 511 : y);

    m_image.setPixel(x,
                     y, val);
}

void MainWindow::clearBoolArray()
{
    for (int i = 0; i < 512*1024; i++)
    {
        m_map[i] = false;
    }

    for (int x = 0; x < 1024; x++)
    {
        for (int y = 0; y < 512; y++)
        {
            setPx(x, y, 0);
        }
    }
}

void MainWindow::refreshView()
{
    for (int i = 0; i < m_participants.size(); i++)
    {
        if (m_participants.at(i)->getPosition() - 1 >= 0 && m_participants.at(i)->getPosition() - 1 < m_labelsPos.size())
        {
            if (m_labelsPos.at(m_participants.at(i)->getPosition() - 1)->isHidden())
            {
                m_labelsPos.at(m_participants.at(i)->getPosition() - 1)->setHidden(false);
                m_labelsName.at(m_participants.at(i)->getPosition() - 1)->setHidden(false);
                m_labelsCar.at(m_participants.at(i)->getPosition() - 1)->setHidden(false);
                m_backgrWidgets.at(m_participants.at(i)->getPosition() - 1)->setHidden(false);
                if (i < 31)
                    m_lineSeps.at(i)->setHidden(false);
            }

            if (m_participants.at(i)->getName() == ui->lineEdit_ownName->text())
            {
                m_backgrWidgets.at(m_participants.at(i)->getPosition() - 1)->setStyleSheet("background-color:#0000FF ;");
            }
            else if (isFriend(m_participants.at(i)->getName()))
            {
                m_backgrWidgets.at(m_participants.at(i)->getPosition() - 1)->setStyleSheet("background-color:#DAA520;");
            }
            else
            {
                m_backgrWidgets.at(m_participants.at(i)->getPosition() - 1)->setStyleSheet("background-color:white;");
            }


            m_labelsPos.at(m_participants.at(i)->getPosition() - 1)->setText(QString::number(m_participants.at(i)->getPosition()) + ".");
            m_labelsName.at(m_participants.at(i)->getPosition() - 1)->setText(m_participants.at(i)->getName());
            m_labelsCar.at(m_participants.at(i)->getPosition() - 1)->setText(m_participants.at(i)->getCar());

            //m_labelsPos.at(m_participants.at(i)->getPosition() - 1)->setStyleSheet("QLabel { background-color : green; color : black; }");
            //m_labelsName.at(m_participants.at(i)->getPosition() - 1)->setStyleSheet("QLabel { background-color : green; color : black; }");
            //m_labelsCar.at(m_participants.at(i)->getPosition() - 1)->setStyleSheet("QLabel { background-color : green; color : black; }");
        }
        else
        {
            //ui->label_debug->setText("Out of range: " + QString::number(m_participants.at(i)->getPosition() - 1));
        }
    }

    for (int i = m_participants.size(); i < 32; i++)
    {
        m_labelsPos.at(i)->setHidden(true);
        m_labelsName.at(i)->setHidden(true);
        m_labelsCar.at(i)->setHidden(true);
        m_backgrWidgets.at(i)->setHidden(true);
        //if (i < 31)
        //    m_lineSeps.at(i)->setHidden(true);
    }
}

void MainWindow::runningCheckedChanged(int newState)
{
    //ui->checkBoxRunning->setText(QString::number(newState));

    if (newState == 0)
    {
        if (fileHandle != NULL)
            CloseHandle( fileHandle );

        ui->label_Status->setText("Is stopped");
        timer->stop();
    }
    else
    {
        fileHandle = OpenFileMapping( PAGE_READONLY, FALSE, convertCharArrayToLPCWSTR(MAP_OBJECT_NAME) );
        if (fileHandle == NULL)
        {
            ui->label_Status->setText("Could not open file mapping object (" + QString::number(GetLastError()) + ").");
        }
        else
        {
            sharedData = (SharedMemory*)MapViewOfFile( fileHandle, PAGE_READONLY, 0, 0, sizeof(SharedMemory) );
            if (sharedData == NULL)
            {
                ui->label_Status->setText("Could not map view of file (" + QString::number(GetLastError()) + ").");

                CloseHandle( fileHandle );
            }
            else
            {
                // Ensure we're sync'd to the correct data version
                if ( sharedData->mVersion != SHARED_MEMORY_VERSION )
                {
                    ui->label_Status->setText("Data version mismatch");
                }
                else
                {
                    for (int x = 0; x < 1024; x++)
                    {
                        for (int y = 0; y < 512; y++)
                        {
                            setPx(x, y, 0);
                        }
                    }
                    m_maxX = -1;
                    m_minX = -1;
                    m_maxY = -1;
                    m_minY = -1;
                    ui->label_Status->setText("Is running");
                    timer->start(25);
                }
            }
        }


    }
}

























bool MainWindow::isFriend(QString playerName)
{
    QTextDocument *doc = ui->textEdit_FriendsNames->document();
    for (int i = 0; i < doc->lineCount(); i++)
    {
        if (playerName == doc->findBlockByLineNumber(i).text())
        {
            return true;
        }
    }

    return false;
}

QString MainWindow::getGameStateString(int gameState)
{
    switch (gameState)
    {
    case 0:
        return "Game exited";
    case 1:
        return "Front End";
    case 2:
        return "Ingame playing";
    case 3:
        return "Ingame paused";
    case 4:
        return "Game max";
    default:
        return "Unknown";
    }
}

QString MainWindow::getSessionStateString(int sessionState)
{
    switch (sessionState)
    {
    case 0:
        return "Invalid";
    case 1:
        return "Practice";
    case 2:
        return "Test";
    case 3:
        return "Qualifying";
    case 4:
        return "Formation lap";
    case 5:
        return "Race";
    case 6:
        return "Time attack";
    case 7:
        return "Session max";
    default:
        return "Unknown";
    }
}

wchar_t* MainWindow::convertCharArrayToLPCWSTR(const char* charArray)
{
    wchar_t* wString=new wchar_t[4096];
    MultiByteToWideChar(CP_ACP, 0, charArray, -1, wString, 4096);
    return wString;
}









