#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <vector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
  void	AddFile(void);
  void	sendFile(void);

private:
    Ui::MainWindow *ui;
    QStringList	_saveFile;
    bool canOpen();
    QCheckBox	*_saveBox;
    std::vector<QCheckBox *>	_allBox;
    std::string	getInformation(void);
    std::string	getLastInformation(std::string &);

};

#endif // MAINWINDOW_H
