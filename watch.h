#ifndef WATCH_H
#define WATCH_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Watch;
}
QT_END_NAMESPACE

class Watch : public QWidget
{
    Q_OBJECT

public:
    Watch(QWidget *parent = nullptr);
    ~Watch();

private:
    Ui::Watch *ui;
};
#endif // WATCH_H
