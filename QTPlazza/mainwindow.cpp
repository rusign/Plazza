//
// mainwindow.cpp for  in /home/mart_4/cpp_plazza/QT/QTPlazza
//
// Made by mart_4
// Login   <mart_4@epitech.net>
//
// Started on  Fri Apr 22 21:26:47 2016 mart_4
// Last update Sun Apr 24 22:46:02 2016 mart_4
//

#include <fstream>
#include <QFileDialog>
#include <QDir>
#include <QListWidgetItem>
#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);
}

MainWindow::~MainWindow(void)
{
  delete ui;
}

void MainWindow::AddFile(void)
{
  QString tmp("");
  QStringList files = QFileDialog::getOpenFileNames(this, "Windows Plazza", QDir::currentPath(), "HTML file (*.html);; CSS file (*.css);; TEXT file (*.txt);; ALL file (*)");
  for (auto file = files.begin(); file != files.end(); file++)
    {
      tmp += *file;
      tmp += "\n";
    }
  QMessageBox::information(this, "File selected", "Warning : Are you sure you want to select these files?\n" + tmp);
  while (ui->FileList->count() > 0)
    {
      delete ui->FileList->takeItem(0);
    }
  _saveFile = files;

  for (auto file = files.begin(); file != files.end(); file++)
    {
      QListWidgetItem *item = new QListWidgetItem();

      item->setText(*file);
      ui->FileList->addItem(item);
    }
}

bool	MainWindow::canOpen(void)
{
  int	error(0);

  for (auto file = _saveFile.begin(); file != _saveFile.end(); ++file)
    {
      std::ofstream	_file;
      std::string	test("result.txt");

      _file.open(file->toStdString(), std::ofstream::out | std::ofstream::app);
      if (_file);
      else ++error;
    }
  return (error > 0) ? false : true;
}

std::string	MainWindow::getLastInformation(std::string &tmp)
{
  if (ui->checkBox_3->isChecked())
    {
      tmp.clear();
      tmp += "EMAIL_ADDRESS";
    }
  return (tmp);
}

std::string	MainWindow::getInformation()
{
  std::string	tmp("");

  if (ui->checkBox->isChecked())
    {
      tmp += "PHONE_NUMBER";
    }
  else if (ui->checkBox_2->isChecked())
    {
      tmp.clear();
      tmp += "IP_ADDRESS";
    }
  return (getLastInformation(tmp));
}

void	MainWindow::sendFile(void)
{
  std::vector<std::string>	_strings;
  std::ofstream			_file;
  std::string			_tmpType;

  if (_saveFile.isEmpty() || !canOpen())
    {
      QMessageBox::critical(this, "WindowsToSend", "Error: no files have been selected");
      return ;
    }
  _tmpType = this->getInformation();
  _file.open("resultFile.txt", std::ofstream::out | std::ofstream::app);
  if (_file)
    {
      for (auto file = _saveFile.begin(); file != _saveFile.end(); ++file)
	{
	  _file << file->toStdString() << " ";
	}
      if (_tmpType.size() == 0)
	_tmpType += " EMAIL_ADDRESS;\n";
      _file << " " << _tmpType << ";\n";
      _file.close();
    }
  QMessageBox::information(this, "WindowsToSend", "Success : All files have been properly sent");
}
