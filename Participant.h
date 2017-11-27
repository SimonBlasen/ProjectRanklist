#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include <QString>

class Participant
{
public:
    Participant();

    int getPosition();
    QString getName();
    QString getCar();
    float getWorldPositionX();
    float getWorldPositionY();
    float getWorldPositionZ();
    float getOldWorldPositionX();
    float getOldWorldPositionY();
    float getOldWorldPositionZ();

    void setPosition(int position);
    void setName(QString name);
    void setCar(QString car);
    void setWorldPosition(float x, float y, float z);
    void setOldWorldPosition(float x, float y, float z);
private:

    float m_old_worldPosition_x;
    float m_old_worldPosition_y;
    float m_old_worldPosition_z;
    float m_worldPosition_x;
    float m_worldPosition_y;
    float m_worldPosition_z;
    int m_position;
    QString m_name;
    QString m_car;

};

#endif // PARTICIPANT_H
