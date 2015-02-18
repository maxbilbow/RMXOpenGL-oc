//
//  PointOfView.h
//  OpenGL 2.0
//
//  Created by Max Bilbow on 23/01/2015.
//  Copyright (c) 2015 Rattle Media Ltd. All rights reserved.
//

@interface PointOfView : NSObject


@end

@implementation PointOfView
    

//- (GLKVector3)getEye
//{
//        NSLog(@"EYE not overriden");
//        return GLKVector3Make(0,0,0);
//}
//    
//- (GLKVector3)getCenter
//{
//        NSLog(@"CENTER not overriden");
//        return GLKVector3Make(0,0,1);
//    }
//    
//- (GLKVector3)getUp
//{
//        NSLog(@"UP not overriden");
//        return GLKVector3Make(0,1,0);
//}
//   
//
//    GLKMatrix4 makeLookAt(GLKMatrix4 (*lookAt)(float eyeX,float eyeY, float eyeZ, float cx,float cy, float cz, float ux,float uy, float uz )){
//        return (GLKMatrix4)lookAt(
//                             getEye().x,   getEye().y,     getEye().z,
//                             getCenter().x, getCenter().y, getCenter().z,
//                             getUp().x,     getUp().y,     getUp().z
//                             );
//    }
//    
//    
//    GLKMatrix4 makePerspective(GLKMatrix4 (*make)(float fovyRadians, float aspect, float nearZ, float farZ), float m, int width, int height){//, Number fovyRadians, Number aspect, Number nearZ, Number farZ){
//        
//        return (GLKMatrix4)make(60*m ,width / height, 1.0, 1000.0);
//    }
@end