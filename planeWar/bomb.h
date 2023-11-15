#ifndef BOMB_H
#define BOMB_H
#include "config.h"
#include <QVector>
#include <QPixmap>

class Bomb
{
public:
    Bomb();

    // 更新信息(播放图片下标，播放间隔)
    void updateInfo();

public:
    // 爆炸资源数组
    QVector<QPixmap> m_pixarr;

    // 爆炸位置
    int m_x;
    int m_y;

    // 爆炸状态
    bool m_free;

    // 爆炸切图的时间间隔
    int m_recorder;

    // 爆炸时加载图片下标
    int m_index;
};

#endif // BOMB_H
