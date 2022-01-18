#include <QApplication>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QRegularExpression>

void validNumber(QLabel* messageLabel){
    messageLabel->setText("Ok");
    messageLabel->setStyleSheet("QLabel { color: green; }");
}//message about a correctly dialed phone
void notValidNumber(QLabel* messageLabel){
    messageLabel->setText("Not ok");
    messageLabel->setStyleSheet("QLabel { color: red; }");
}//message about an incorrectly dialed phone

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    auto* win = new QWidget(nullptr);
    auto* vbox = new QVBoxLayout(win);

    auto* lineEdit = new QLineEdit();
    lineEdit->setStyleSheet("QLineEdit { font-size: 14px }");
    lineEdit->setPlaceholderText("Phone number(example: +11111111111)");

    auto* messageLabel = new QLabel();
    messageLabel->setStyleSheet("QLabel { font-size: 12px }");

    vbox->addWidget(lineEdit);
    vbox->addWidget(messageLabel);

    QObject::connect(lineEdit, &QLineEdit::textEdited, [messageLabel](QString currentText){
        QRegularExpression regularExpression("\\+[0-9]{11}$");
        if(!currentText.isEmpty()){
            if(regularExpression.match(currentText).hasMatch()){
                validNumber(messageLabel);
            }else{
                notValidNumber(messageLabel);
            }
        }else{
            messageLabel->clear();
        }
    });

    win->setFixedSize(400, 90);
    win->show();

    return QApplication::exec();
} //
