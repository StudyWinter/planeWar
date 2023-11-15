#include "bomb.h"
#include "config.h"

Bomb::Bomb()
{
    // 初始化爆炸图片数组
    for (int i = 0; i < BOMB_NUM; i++) {
        // 字符串拼接，类似 ":/res/bobm-1.png"
        QString str = QString(BOMB_PATH).arg(i);
        m_pixarr.push_back(QPixmap(str));
    }

    // 初始化坐标
    m_x = 0;
    m_y = 0;

    // 初始化空闲状态
    m_free = true;

    // 当前播放图片下标
    m_index = 0;

    // 爆炸间隔记录
    m_recorder = 0;
}

// 更新信息
void Bomb::updateInfo()
{
    // 空闲状态
    if (m_free) {
        return;
    }

    m_recorder++;

    if (m_recorder < BOMB_INTERVAl) {
        // 记录爆炸间隔未到，直接return，不需要切图
        return;
    }

    // 重置
    m_recorder = 0;

    // 切换爆炸播放图片
    m_index++;
    if (m_index > BOMB_MAX - 1) {
        m_index = 0;
        m_free = true;
    }

}
