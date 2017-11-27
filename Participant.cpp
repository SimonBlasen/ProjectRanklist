#include "Participant.h"

Participant::Participant()
{
    m_position = 0;
    m_name = "";
    m_car = "";
}

int Participant::getPosition()
{
    return m_position;
}

void Participant::setPosition(int position)
{
    m_position = position;
}

QString Participant::getName()
{
    return m_name;
}

void Participant::setName(QString name)
{
    m_name = name;
}

QString Participant::getCar()
{
    return m_car;
}

void Participant::setCar(QString car)
{
    m_car = car;
}

void Participant::setWorldPosition(float x, float y, float z)
{
    setOldWorldPosition(m_worldPosition_x, m_worldPosition_y, m_worldPosition_z);
    m_worldPosition_x = x;
    m_worldPosition_y = y;
    m_worldPosition_z = z;
}

float Participant::getWorldPositionX()
{
    return m_worldPosition_x;
}

float Participant::getWorldPositionY()
{
    return m_worldPosition_y;
}

float Participant::getWorldPositionZ()
{
    return m_worldPosition_z;
}

void Participant::setOldWorldPosition(float x, float y, float z)
{
    m_old_worldPosition_x = x;
    m_old_worldPosition_y = y;
    m_old_worldPosition_z = z;
}

float Participant::getOldWorldPositionX()
{
    return m_old_worldPosition_x;
}

float Participant::getOldWorldPositionY()
{
    return m_old_worldPosition_y;
}

float Participant::getOldWorldPositionZ()
{
    return m_old_worldPosition_z;
}
