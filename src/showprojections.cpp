#include "include/showprojections.h"
#include "ui_showprojections.h"
#include <iostream>
#include "include/mainwindow.h"
#include <QApplication>
#include <math.h>
#include <QtCore>
#include <QtWidgets>
#include "include/wireframe.h"
#include "include/EdgeList2D.h"
#include "include/generalMethods.h"
#include "include/Plane.h"
#include "include/VertexList2D.h"
#include "include/basicLoopEdgeSet.h"
#include "include/bodyLoop.h"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>

#define PI 3.1415926536
#define SIZE 99
#define FACTOR 100

const float STEP = 2*PI/SIZE;

using namespace Qt;
ShowProjections::ShowProjections(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ShowProjections)
{

    ui->setupUi(this);
    this->setWindowTitle("Projections");

}

ShowProjections::~ShowProjections()
{
    delete ui;
}

void ShowProjections::generateView() {
    std::cout<< "Inside showProjections\n";

        FILE * file;
        std::cout << objfileName;
    //         strcat(fileName1,".obj");
         file = fopen(objfileName.c_str(), "r");
         // generate a body with this obj file and take its projection
         wireFrame wireframe;
         vertex3D localVertex;
         edge3D localEdge;
         int firstVertex, secondVertex;
         int flagEndOfFile = 0;
//<<<<<<< HEAD
//         while( 1 ){
//             cout<<"starting loop"<<endl ;
//             char lineHeader[128];
//             // read the first word of the line
//             int res = 0  ;
//             res = fscanf(file, "%s", lineHeader);
//             cout<<"1"<<endl ;
//             if (res == EOF)
//                 break; // EOF = End Of File. Quit the loop.
//             cout << lineHeader;
//             // else : parse lineHeader
//             if ( strcmp( lineHeader, "v" ) == 0 ){
//                 //cout << "v ";
//                 fscanf(file, "%f %f %f\n", &localVertex.a, &localVertex.b, &localVertex.c );
//                 wireframe.addVertex(localVertex);
//                 generalMethods::printVertex(localVertex);cout << "\n";

//             }
//             else if ( strcmp( lineHeader, "vt" ) == 0 ){
//                 char c = ' ';
//                 //cout << "vt ";
//                 while(c!='\n'){
//                     fscanf(file, "%c", &c);
//                     cout << c;
//                 }
//             }
//             else if ( strcmp( lineHeader, "vn" ) == 0 ){
//                 char c = ' ';
//                // cout <<"vn ";
//                 while(c!='\n'){
//                     fscanf(file, "%c", &c);
//                     cout << c;
//                 }
//             }
//             else if ( strcmp( lineHeader, "f" ) == 0 ){
//                 //cout << "f ";
//                 fscanf(file, "%d",&firstVertex);
//                 cout << firstVertex;
//                 while(1){
//                     char c;
//                     fscanf(file, "%c", &c);
//                     if(c == '/'){
//                         cout << c;
//                         while(c!=' '){
//                             fscanf(file, "%c", &c);
//                             cout << c;
//                         }
//                     }
//                     else if(c == ' '){
//                         cout << c;
//                     }
//                     else if(c == EOF){
//                         flagEndOfFile =1;
//                         break;
//                     }
//                     else if(c == '\n'){
//                         cout << c;
//                         break;
//                     }
//                     fscanf(file, "%d",&secondVertex);
//                     cout << secondVertex;
//                     wireframe.addEdge({ wireframe.vertexList.at(firstVertex-1), wireframe.vertexList.at(secondVertex-1) });

//                     firstVertex = secondVertex;
//                 }
//                 if(flagEndOfFile == 1) break;
//             }
//             else if( strcmp( lineHeader, "\n" ) == 0)
//                 {cout <<"\n";}
//             else{
//                 char c = ' ';
//                 while(c!='\n'){
//                     fscanf(file, "%c", &c);
//                     cout << c;
//                 }
//             }
//         // end of while
//             cout<<"end loop"<<endl ;
//         }
//=======
        while( 1 ){

            char lineHeader[128];

            // read the first word of the line
            int res = fscanf(file, "%s", lineHeader);
            if (res == EOF)
                break; // EOF = End Of File. Quit the loop.
            cout << lineHeader;
            // else : parse lineHeader
            if ( strcmp( lineHeader, "v" ) == 0 ){
                //cout << "v ";
                fscanf(file, "%f %f %f\n", &localVertex.a, &localVertex.b, &localVertex.c );
                wireframe.addVertex(localVertex);
                generalMethods::printVertex(localVertex);cout << "\n";

            }
            else if ( strcmp( lineHeader, "vt" ) == 0 ){
                char c = ' ';
               // cout << "vt ";
                while(c!='\n'){
                    fscanf(file, "%c", &c);
                    cout << c;
                }
            }
            else if ( strcmp( lineHeader, "vn" ) == 0 ){
                char c = ' ';
                //cout <<"vn ";
                while(c!='\n'){
                    fscanf(file, "%c", &c);
                    cout << c;
                }
            }
            else if ( strcmp( lineHeader, "f" ) == 0 ){
                //cout << "f ";
                fscanf(file, "%d",&firstVertex);
                cout << firstVertex;
                while(1){
                    char c;
                    fscanf(file, "%c", &c);
                    // if(c == '/'){
                    //     cout << c;
                    //     while(c!=' '){
                    //         fscanf(file, "%c", &c);
                    //         cout << c;
                    //     }
                    // }
                    if(c == ' '){
                        cout << c;
                    }
                    else if(c == EOF){
                        flagEndOfFile =1;
                        break;
                    }
                    else if(c == '\n'){
                        cout << c;
                        break;
                    }
                    fscanf(file, "%d",&secondVertex);
                    cout << secondVertex;
                    wireframe.addEdge({ wireframe.vertexList.at(firstVertex-1), wireframe.vertexList.at(secondVertex-1) });

                    firstVertex = secondVertex;
                }
                if(flagEndOfFile == 1) break;
            }
            else if( strcmp( lineHeader, "\n" ) == 0)
                {
                //    cout <<"\n";
                }
            else{
                char c = ' ';
                while(c!='\n'){
                    fscanf(file, "%c", &c);
                    cout << c;
                }
            }
        // end of while
        }
//>>>>>>> d71eb707f2b67fce37676868d1921d36fb2a1869
//          this->wireframeattr = wireframe ;;
          wireframe.generateFullBody();
          TwoDObj *twodObj = new TwoDObj(wireframe.vertexList, wireframe.edgeList ,  wireframe.getfaces() ) ;
          this->twoDObjAttr = twodObj ;;

          // will write the views into a text file so that this 
          // txt file can be used for reconstruction later


//          cout<<"calling getviews" << endl ;
          draw() ;
//          float angles[] = {0.0 , 0.0 , 1.0 } ;
//          twodObj->applyRotation(angles);
//          std::vector< std::vector<edge2D> > views = twodObj->getViews() ;
//          std::vector<edge2D> topViewEdges = views[0] ;
//          std::vector<edge2D> frontViewEdges = views[1] ;
//          std::vector<edge2D> sideViewEdges = views[2] ;
//          std::vector<edge2D> isometricView = views[3] ;
//          std::vector<edge2D> topViewHidden = views[4] ;
//          std::vector<edge2D> frontViewHidden = views[5] ;
//          std::vector<edge2D> sideViewHidden = views[6] ;
//          float* firstPoint ;
//          float* secondPoint ;
//    //      QApplication a(argc, argv);
//          QLabel *lfv =  ui->frontView ;
//          QPicture pifv;
//          QPainter pfv(&pifv);
//          QLabel *lsv = ui->sideView ;
//          QPicture pisv;
//          QPainter psv(&pisv);
//          QLabel *ltv = ui->TopView ;
//          QPicture pitv;
//          QPainter ptv(&pitv);
//          QLabel *lip = ui->Isometric ;
//          QPicture piip;
//          QPainter pip(&piip);
//          edge2D currentEdge ;
//          pfv.setRenderHint(QPainter::Antialiasing);
//          psv.setRenderHint(QPainter::Antialiasing);
//          ptv.setRenderHint(QPainter::Antialiasing);
//          pip.setRenderHint(QPainter::Antialiasing);
//          pfv.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap));
//          ptv.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap));
//          psv.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap));

//          pfv.scale(0.9,-0.9);
//          psv.scale(0.9,-0.9);
//          ptv.scale(0.9,-0.9);
//          pip.scale(0.7,-0.7);
//      //    p.translate(-600,-600);

//          // p.drawLine(0, 0, 200, 200);
//          float x, y, prev_x=0, prev_y=0 ;
//          for(unsigned i = 0 ; i < frontViewHidden.size();i+=1){
//              currentEdge = frontViewHidden[i] ;
//              firstPoint = currentEdge.v1.getCoordinates() ;
//              secondPoint = currentEdge.v2.getCoordinates() ;
//              pfv.drawLine(firstPoint[0],firstPoint[1],secondPoint[0],secondPoint[1] );
//          }
//          for(unsigned i = 0 ; i < sideViewHidden.size();i+=1){
//              currentEdge = sideViewHidden[i] ;
//              firstPoint = currentEdge.v1.getCoordinates() ;
//              secondPoint = currentEdge.v2.getCoordinates() ;
//              psv.drawLine(firstPoint[0],firstPoint[1],secondPoint[0],secondPoint[1] );
//          }
//          for(unsigned i = 0 ; i < topViewHidden.size();i+=1){
//              currentEdge = topViewHidden[i] ;
//              firstPoint = currentEdge.v1.getCoordinates() ;
//              secondPoint = currentEdge.v2.getCoordinates() ;
//              ptv.drawLine(firstPoint[0],firstPoint[1],secondPoint[0],secondPoint[1] );
//          }
//          pfv.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap));
//          psv.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap));
//          ptv.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap));
//          pip.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap));
//          for(unsigned i = 0 ; i < topViewEdges.size();i+=1){
//              currentEdge = topViewEdges[i] ;
//              firstPoint = currentEdge.v1.getCoordinates() ;
//              secondPoint = currentEdge.v2.getCoordinates() ;
//              ptv.drawLine(firstPoint[0],firstPoint[1],secondPoint[0],secondPoint[1] );
//          }
//          for(unsigned i = 0 ; i < frontViewEdges.size();i+=1){
//              currentEdge = frontViewEdges[i] ;
//              firstPoint = currentEdge.v1.getCoordinates() ;
//              secondPoint = currentEdge.v2.getCoordinates() ;
//              pfv.drawLine(firstPoint[0],firstPoint[1],secondPoint[0],secondPoint[1] );
//          }
//          for(unsigned i = 0 ; i < sideViewEdges.size();i+=1){
//              currentEdge = sideViewEdges[i] ;
//              firstPoint = currentEdge.v1.getCoordinates() ;
//              secondPoint = currentEdge.v2.getCoordinates() ;
//              psv.drawLine(firstPoint[0],firstPoint[1],secondPoint[0],secondPoint[1] );
//          }
//          for(unsigned i = 0 ; i < isometricView.size();i+=1){
//              currentEdge = isometricView[i] ;
//              firstPoint = currentEdge.v1.getCoordinates() ;
//              secondPoint = currentEdge.v2.getCoordinates() ;
//              pip.drawLine(firstPoint[0],firstPoint[1],secondPoint[0],secondPoint[1] );
//          }
//          float* set = twodObj->getMinXY() ;
////          p.drawLine(400+set[1],-100+set[0],400+set[1],1000+set[0]);
////          p.drawLine(0+set[1],400+set[0],900+set[1],400+set[0]);


////          p.end(); // Don't forget this line!

////          l.setPicture(pi);
////          l.show();
//          psv.end() ;
//          pfv.end();
//          ptv.end() ;
//          pip.end() ;
//          lfv->setPicture(pifv);
//          ltv->setPicture(pitv);
//          lsv->setPicture(pisv);
//          lip->setPicture(piip);


       //   QLabel l2 ;
        //  l2.setPicture(pi);
        //  l2.show();
    //      return a.exec();
    //      end of 3d->2d

}

void ShowProjections::on_xSlider_valueChanged(int value)
{
    angleX = value*STEP;
//    cout<<"see value here"<<value*STEP<<endl ;
    float angles[] = {angleX , angleY , angleZ } ;
    this->twoDObjAttr->applyRotation(angles);
    draw();


}

void ShowProjections::draw() {
    std::vector< std::vector<edge2D> > views = twoDObjAttr->getViews() ;
    std::vector<edge2D> topViewEdges = views[0] ;
    std::vector<edge2D> frontViewEdges = views[1] ;
    std::vector<edge2D> sideViewEdges = views[2] ;
    std::vector<edge2D> isometricView = views[3] ;
    std::vector<edge2D> topViewHidden = views[4] ;
    std::vector<edge2D> frontViewHidden = views[5] ;
    std::vector<edge2D> sideViewHidden = views[6] ;
    float* firstPoint ;
    float* secondPoint ;
//      QApplication a(argc, argv);
    QLabel *lfv =  ui->frontView ;
    QPicture pifv;
    QPainter pfv(&pifv);
    QLabel *lsv = ui->sideView ;
    QPicture pisv;
    QPainter psv(&pisv);
    QLabel *ltv = ui->TopView ;
    QPicture pitv;
    QPainter ptv(&pitv);
    QLabel *lip = ui->Isometric ;
    QPicture piip;
    QPainter pip(&piip);
    edge2D currentEdge ;
    pfv.setRenderHint(QPainter::Antialiasing);
    psv.setRenderHint(QPainter::Antialiasing);
    ptv.setRenderHint(QPainter::Antialiasing);
    pip.setRenderHint(QPainter::Antialiasing);
    pfv.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap));
    ptv.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap));
    psv.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap));

    pfv.scale(0.9,-0.9);
    psv.scale(0.9,-0.9);
    ptv.scale(0.9,-0.9);
    pip.scale(0.7,-0.7);
//    p.translate(-600,-600);

    // p.drawLine(0, 0, 200, 200);
    float x, y, prev_x=0, prev_y=0 ;
    for(unsigned i = 0 ; i < frontViewHidden.size();i+=1){
        currentEdge = frontViewHidden[i] ;
        firstPoint = currentEdge.v1.getCoordinates() ;
        secondPoint = currentEdge.v2.getCoordinates() ;
        pfv.drawLine(firstPoint[0],firstPoint[1],secondPoint[0],secondPoint[1] );
    }
    for(unsigned i = 0 ; i < sideViewHidden.size();i+=1){
        currentEdge = sideViewHidden[i] ;
        firstPoint = currentEdge.v1.getCoordinates() ;
        secondPoint = currentEdge.v2.getCoordinates() ;
        psv.drawLine(firstPoint[0],firstPoint[1],secondPoint[0],secondPoint[1] );
    }
    for(unsigned i = 0 ; i < topViewHidden.size();i+=1){
        currentEdge = topViewHidden[i] ;
        firstPoint = currentEdge.v1.getCoordinates() ;
        secondPoint = currentEdge.v2.getCoordinates() ;
        ptv.drawLine(firstPoint[0],firstPoint[1],secondPoint[0],secondPoint[1] );
    }
    pfv.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap));
    psv.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap));
    ptv.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap));
    pip.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap));
    for(unsigned i = 0 ; i < topViewEdges.size();i+=1){
        currentEdge = topViewEdges[i] ;
        firstPoint = currentEdge.v1.getCoordinates() ;
        secondPoint = currentEdge.v2.getCoordinates() ;
        ptv.drawLine(firstPoint[0],firstPoint[1],secondPoint[0],secondPoint[1] );
    }
    for(unsigned i = 0 ; i < frontViewEdges.size();i+=1){
        currentEdge = frontViewEdges[i] ;
        firstPoint = currentEdge.v1.getCoordinates() ;
        secondPoint = currentEdge.v2.getCoordinates() ;
        pfv.drawLine(firstPoint[0],firstPoint[1],secondPoint[0],secondPoint[1] );
    }
    for(unsigned i = 0 ; i < sideViewEdges.size();i+=1){
        currentEdge = sideViewEdges[i] ;
        firstPoint = currentEdge.v1.getCoordinates() ;
        secondPoint = currentEdge.v2.getCoordinates() ;
        psv.drawLine(firstPoint[0],firstPoint[1],secondPoint[0],secondPoint[1] );
    }
    for(unsigned i = 0 ; i < isometricView.size();i+=1){
        currentEdge = isometricView[i] ;
        firstPoint = currentEdge.v1.getCoordinates() ;
        secondPoint = currentEdge.v2.getCoordinates() ;
        pip.drawLine(firstPoint[0],firstPoint[1],secondPoint[0],secondPoint[1] );
    }
//    float* set = twodObj->getMinXY() ;
//          p.drawLine(400+set[1],-100+set[0],400+set[1],1000+set[0]);
//          p.drawLine(0+set[1],400+set[0],900+set[1],400+set[0]);


//          p.end(); // Don't forget this line!

//          l.setPicture(pi);
//          l.show();
    psv.end() ;
    pfv.end();
    ptv.end() ;
    pip.end() ;
    lfv->setPicture(pifv);
    ltv->setPicture(pitv);
    lsv->setPicture(pisv);
    lip->setPicture(piip);
}




 //   QLabel l2 ;
  //  l2.setPicture(pi);
  //  l2.show();
//      return a.exec();
//      end of 3d->2d


void ShowProjections::on_ySlider_valueChanged(int value)
{
    angleY = value*STEP;
    float angles[] = {angleX , angleY , angleZ } ;
    this->twoDObjAttr->applyRotation(angles);
    draw();
}

void ShowProjections::on_zSlider_valueChanged(int value)
{
    angleZ = value*STEP;
    float angles[] = {angleX , angleY , angleZ } ;
    this->twoDObjAttr->applyRotation(angles);
    draw();
}

void ShowProjections::on_horizontalSlider_valueChanged(int value)
{
    this->twoDObjAttr->factor = value*8 ;
    draw() ;
}

void ShowProjections::on_pushButton_clicked()
{
    QString filenameTemp = QFileDialog::getSaveFileName(this, "Save file", "", ".txt") ;
    filenameTemp += ".txt" ;
    QFile f( filenameTemp );
    f.open( QIODevice::WriteOnly );
    QTextStream txtFile(&f);

//    size_t lastindex = objfileName.find_last_of(".");
//    string rawname = objfileName.substr(0, lastindex);
//    rawname += ".txt";

    //txtFile << "Writing this to a file.\n";
      std::vector<edge2D> topViewToWrite = this->twoDObjAttr->noChangeTopView;
      std::vector<edge2D> frontViewToWrite = this->twoDObjAttr->noChangeFrontView;
      std::vector<edge2D> sideViewToWrite = this->twoDObjAttr->noChangeSideView;

      VertexList2D topViewVertexToWrite;
      VertexList2D frontViewVertexToWrite;
      VertexList2D sideViewVertexToWrite;

       for (int i = 0; i < frontViewToWrite.size() ; i++){
          frontViewVertexToWrite.addVertex(frontViewToWrite.at(i).v1);
          frontViewVertexToWrite.addVertex(frontViewToWrite.at(i).v2);
       }

       for (int i = 0; i < topViewToWrite.size() ; i++){
          topViewVertexToWrite.addVertex(topViewToWrite.at(i).v1);
          topViewVertexToWrite.addVertex(topViewToWrite.at(i).v2);
       }

       for (int i = 0; i < sideViewToWrite.size() ; i++){
          sideViewVertexToWrite.addVertex(sideViewToWrite.at(i).v1);
          sideViewVertexToWrite.addVertex(sideViewToWrite.at(i).v2);
       }


//    ofstream txtFile;
//    txtFile.open (rawname);

      for (int i = 0; i < topViewVertexToWrite.vertexList.size() ; i++){
          txtFile << "t " << topViewVertexToWrite.vertexList.at(i).a << " " << topViewVertexToWrite.vertexList.at(i).b << "\n";
       }

       for (int i = 0; i < topViewToWrite.size() ; i++){
          vector<vertex2D>::iterator it;
          it = std::find(topViewVertexToWrite.vertexList.begin(), topViewVertexToWrite.vertexList.end(), topViewToWrite.at(i).v1) ;
          int a = std::distance(topViewVertexToWrite.vertexList.begin(), it) +1;

          it = std::find(topViewVertexToWrite.vertexList.begin(), topViewVertexToWrite.vertexList.end(), topViewToWrite.at(i).v2) ;
          int b = std::distance(topViewVertexToWrite.vertexList.begin(), it) +1;

          txtFile << "te " << a << " " << b << "\n";
       }


      for (int i = 0; i < sideViewVertexToWrite.vertexList.size() ; i++){
          txtFile << "s " << sideViewVertexToWrite.vertexList.at(i).a << " " << sideViewVertexToWrite.vertexList.at(i).b << "\n";
       }

       for (int i = 0; i < sideViewToWrite.size() ; i++){
          vector<vertex2D>::iterator it;
          it = std::find(sideViewVertexToWrite.vertexList.begin(), sideViewVertexToWrite.vertexList.end(), sideViewToWrite.at(i).v1) ;
          int a = std::distance(sideViewVertexToWrite.vertexList.begin(), it) +1;

          it = std::find(sideViewVertexToWrite.vertexList.begin(), sideViewVertexToWrite.vertexList.end(), sideViewToWrite.at(i).v2) ;
          int b = std::distance(sideViewVertexToWrite.vertexList.begin(), it) +1;

          txtFile << "se " << a << " " << b << "\n";
       }


      for (int i = 0; i < frontViewVertexToWrite.vertexList.size() ; i++){
          txtFile << "f " << frontViewVertexToWrite.vertexList.at(i).a << " " << frontViewVertexToWrite.vertexList.at(i).b << "\n";
       }

       for (int i = 0; i < frontViewToWrite.size() ; i++){
          vector<vertex2D>::iterator it;
          it = std::find(frontViewVertexToWrite.vertexList.begin(), frontViewVertexToWrite.vertexList.end(), frontViewToWrite.at(i).v1) ;
          int a = std::distance(frontViewVertexToWrite.vertexList.begin(), it) +1;

          it = std::find(frontViewVertexToWrite.vertexList.begin(), frontViewVertexToWrite.vertexList.end(), frontViewToWrite.at(i).v2) ;
          int b = std::distance(frontViewVertexToWrite.vertexList.begin(), it) +1;

          txtFile << "fe " << a << " " << b << "\n";
       }

//    txtFile.close();


    f.close();

}
