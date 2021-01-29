#ifndef DIALOGCONNECT_H
#define DIALOGCONNECT_H

#include <QDialog>

namespace Ui {
class DialogConnect;
}

class DialogConnect : public QDialog
{
    Q_OBJECT

public:
    explicit DialogConnect(QWidget *parent = nullptr);
    ~DialogConnect();

    int getPort();
    QString getHost();

private slots:
    void on_host_textChanged(const QString &arg1);

    void on_port_textChanged(const QString &arg1);

private:
    Ui::DialogConnect *ui;
};

#endif // DIALOGCONNECT_H
