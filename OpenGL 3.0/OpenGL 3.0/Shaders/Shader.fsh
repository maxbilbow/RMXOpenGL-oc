//
//  Shader.fsh
//  OpenGL 3.0
//
//  Created by Max Bilbow on 14/02/2015.
//  Copyright (c) 2015 Rattle Media. All rights reserved.
//

varying lowp vec4 colorVarying;

void main()
{
    gl_FragColor = colorVarying;
}
