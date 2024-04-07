#ifndef LIGHTS_H
#define LIGHTS_H

#include <QPushButton>

class Lights : public QPushButton {
    Q_OBJECT
public:
    enum Width { Large, Small };
    enum Color { Dark_Yellow, Bright_Yellow, Dark_Red, Bright_Red };

    Lights(QWidget* parent = nullptr);

    void setWidth(Width width);
    void setColor(Color color);

private:
    Width m_width;
    Color m_color;
};

#endif // LIGHTS_H
