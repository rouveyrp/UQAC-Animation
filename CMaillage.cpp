//
//  CMaillage.cpp
//  proto
//
//  Created by Jean Meyblum et Pierre Rouveyrol on 2013-01-30.
//  Copyright (c) 2013 YC. All rights reserved.
//

#ifndef __MAC_OS_X__
#include <GL/gl.h>
#else
#include "OpenGL/gl.h"
#endif

#include "CMaillage.h"
#include <algorithm>

using namespace std;

CMaillage::CMaillage(int xsize, int ysize):m_xsize(xsize),m_ysize(ysize),m_cur_sommets(0)
{
    m_sommets = new GLfloat[(m_xsize + 1)*(m_ysize + 1)*8];
    m_indices = new GLuint[(m_xsize+1)*(m_ysize)*6];
    int k = 0;
    for(int i=0; i<m_xsize+1; i++)
    {
        for(int j=0; j<m_ysize; j++)
        {
            m_indices[k] = (i*m_ysize + j);
            m_indices[k + 1] = ((i + 1)*m_ysize + j);
            m_indices[k + 2] = ((i + 1)*m_ysize + (j + 1));
            
            m_indices[k + 3] = (i*m_ysize + j);
            m_indices[k + 4] = ((i + 1)*m_ysize + (j + 1));
            m_indices[k + 5] = (i*m_ysize + (j + 1));
            k += 6;
        }
    }

}

void CMaillage::FillVBO(VBO& vb)
{
    vb.SetBuffers(m_sommets, (m_xsize + 1)*(m_ysize + 1)*8 ,m_indices, (m_xsize+1)*(m_ysize)*6);
}



void CMaillage::AddSommet(vector<float> sommet)
{
    for(int i = 0; i < 8 ; i++){
        m_sommets[i+m_cur_sommets] = sommet[i];
    }
    m_cur_sommets += 8;
}

