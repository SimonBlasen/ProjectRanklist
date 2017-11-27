#ifndef TRACKBORDERS_H
#define TRACKBORDERS_H

#include <QString>

class TrackBorders
{
public:
    TrackBorders();

    static int* getBorders(QString trackname, QString variation);
    static float getBorderMinX(QString trackname, QString variation);
    static float getBorderMaxX(QString trackname, QString variation);
    static float getBorderMinZ(QString trackname, QString variation);
    static float getBorderMaxZ(QString trackname, QString variation);
};

#endif // TRACKBORDERS_H
