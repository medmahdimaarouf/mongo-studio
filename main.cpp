#include "mainwindow.h"

#include <QApplication>
#include<QtDebug>


/*


int testmongo(){



        // The mongocxx::instance constructor and destructor initialize and shut down the driver,
        // respectively. Therefore, a mongocxx::instance must be created before using the driver and
        // must remain alive for as long as the driver is in use.
        qDebug()<<"ok";
        mongocxx::instance inst;

        try {
            const auto uri = mongocxx::uri{mongocxx::uri::k_default_uri};

            auto client = mongocxx::client{uri};
            auto admin = client["admin"];
            auto result = admin.run_command(make_document(kvp("isMaster", 1)));
            std::cout << bsoncxx::to_json(result) << std::endl;

            return EXIT_SUCCESS;
        } catch (const std::exception& xcp) {
            std::cout << "connection failed: " << xcp.what() << std::endl;
            return EXIT_FAILURE;
        }
}


*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //qDebug()<<testmongo();
    MainWindow w;
    w.show();

    return a.exec();
}
