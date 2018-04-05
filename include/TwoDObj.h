#ifndef TWOD_H
#define TWOD_F
#include <vector>
#include "include/structs.h"

using namespace std;

class TwoDObj{
public:
    std::vector<vertex3D> orignalVertices ;
    std::vector<edge3D> orignalEdgeList ;
    std::vector< std::vector<vertex3D> > orignalFaceList ;
    std::vector<vertex3D> vertices ;
    std::vector<edge3D> edgeList ;
    std::vector< std::vector<vertex3D> > faceList ;
    std::vector<edge2D> topView ;
    std::vector<edge2D> frontView ;
    std::vector<edge2D> sideView ;
    std::vector<edge2D> isometricView ;
    std::vector<edge2D> topViewHidden ;
    std::vector<edge2D> topViewVis ;
    std::vector<edge2D> frontViewHidden ;
    std::vector<edge2D> frontViewVis ;
    std::vector<edge2D> sideViewHidden ;
    std::vector<edge2D> sideViewVis ;
    std::vector<edge2D> noChangeTopView ;
    std::vector<edge2D> noChangeSideView ;
    std::vector<edge2D> noChangeFrontView ;
    int factor;
    TwoDObj(std::vector<vertex3D> vertices , std::vector<edge3D> edgeList , std::vector< std::vector<vertex3D> >) ;
//    this.factor = 200 ;
    //! generates Top View
    void generateTopView() ;
    //! generates Top View
    void generateFrontView() ;
    
    void generateSideView() ;
    std::vector<std::vector<edge2D> > getViews() ;
    float* getMinXY() ;
    void generateIsometric() ;
//    bool checkHides(edge3D edge , std::vector<vertex3D> plane , int direction) ;
    bool hiddenInView(edge3D edge , int direction ) ;
    bool checkHides(edge3D edge, std::vector<vertex3D> plane3D , int direction) ;
    edge2D get2DEdge(edge3D edge3d ,  int direction ) ;
    std::vector<vertex2D> getPlane2D(std::vector<vertex3D> plane3D ,  int direction ) ;
    int isInside(std::vector<vertex2D> polygon, int n, vertex2D p) ;
    bool doIntersect(vertex2D p1, vertex2D q1, vertex2D p2, vertex2D q2) ;
    int orientation(vertex2D p, vertex2D q, vertex2D r) ;
    bool onSegment(vertex2D p, vertex2D q, vertex2D r) ;
    bool canHide(edge3D edge, std::vector<vertex3D> plane3D , int direction) ;
    void applyRotation(float angles[3]) ;
    void rotationOnEdges(float rotationM[][3]) ;
    edge3D rotateEdge(edge3D edge ,float rotationM[][3]);
    void rotationOnPlane(float rotationM[][3]);
    std::vector<vertex3D> rotatePlane(float rotationM[][3] , std::vector<vertex3D> plane3D);
    void rotationOnVertices(float rotationM[][3]);
    vertex3D rotateVertex(vertex3D vertex , float rotationM[][3]);
    bool planeContainsEdge(edge3D edge, std::vector<vertex3D> plane3D) ;
    std::vector<edge3D> divideEdge(edge3D edge) ;

};

#endif
