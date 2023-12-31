#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H
#include <QPixmap>
#include "config.h"
#include "enemybullet.h"


class EnemyPlane
{
public:
    EnemyPlane();

    // 更新坐标
    void updatePosition();
    // 发射子弹
    void shoot();
    // 设置飞机位置
    void setPosition(int x, int y);

public:
    // 敌机资源对象
    QPixmap m_enemy;

    // 位置
    int m_x;
    int m_y;

    // 敌机的矩形边框（用于检测碰撞）
    QRect m_rect;

    // 状态
    bool m_free;

    // 速度
    int m_speed;

    //弹匣
    EnemyBullet m_bullets[ENEMY_BULLET_NUM];

    //发射间隔记录
    int m_recorder;
};

#endif // ENEMYPLANE_H
