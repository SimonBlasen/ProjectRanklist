#include "trackborders.h"

TrackBorders::TrackBorders()
{

}


int* TrackBorders::getBorders(QString trackname, QString variation)
{
    if (trackname == "Hockenheim" && variation == "Grand Prix")
    {
        int borders[4];
        borders[0] = -731;
        borders[1] = 733;
        borders[2] = -457;
        borders[3] = 455;
        return borders;
    }
    else if (trackname == "Circuit de Spa-Francorchamps")
    {
        int borders[4];
        borders[0] = -1202;
        borders[1] = 73;
        borders[2] = -313;
        borders[3] = 1751;
        return borders;
    }
    else
    {
        int borders[4];
        borders[0] = 0;
        borders[1] = 1;
        borders[2] = 2;
        borders[3] = 3;
        return borders;
    }
}


float TrackBorders::getBorderMinX(QString trackname, QString variation)
{
    if (trackname == "Hockenheim" && variation == "Grand Prix")
    {
        return -731;
    }
    else if (trackname == "Circuit de Spa-Francorchamps")
    {
        return -1202;
    }
    else
    {
        return -1;
    }
}

float TrackBorders::getBorderMaxX(QString trackname, QString variation)
{
    if (trackname == "Hockenheim" && variation == "Grand Prix")
    {
        return 733;
    }
    else if (trackname == "Circuit de Spa-Francorchamps")
    {
        return 73;
    }
    else
    {
        return -1;
    }
}

float TrackBorders::getBorderMinZ(QString trackname, QString variation)
{
    if (trackname == "Hockenheim" && variation == "Grand Prix")
    {
        return -457;
    }
    else if (trackname == "Circuit de Spa-Francorchamps")
    {
        return -313;
    }
    else
    {
        return -1;
    }
}

float TrackBorders::getBorderMaxZ(QString trackname, QString variation)
{
    if (trackname == "Hockenheim" && variation == "Grand Prix")
    {
        return 455;
    }
    else if (trackname == "Circuit de Spa-Francorchamps")
    {
        return 1751;
    }
    else
    {
        return -1;
    }
}

