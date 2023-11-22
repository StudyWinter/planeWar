#ifndef HEROPLANE_H
#define HEROPLANE_H
#include <QPixmap>
#include <QRect>
#include "herobullet.h"
#include "config.h"


class HeroPlane
{
public:
    HeroPlane();
    // 发射子弹
    void shoot();
    // 设置飞机位置
    void setPosition(int x, int y);

public:
    // 飞机资源对象
    QPixmap m_plane;

    // 飞机坐标
    int m_x;
    int m_y;

    // 飞机的矩形边框
    QRect m_rect;

    //弹匣
    HeroBullet m_bullets[BULLET_NUM];

    //发射间隔记录
    int m_recorder;
};

#endif // HEROPLANE_H
