#include <stdio.h>
#include <string>
#define _USE_MATH_DEFINES
#include <cmath>

#define GLM_FORCE_RADIANS
#include "glm/vec2.hpp"
#include "glm/vec3.hpp"
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/matrix_inverse.hpp"

glm::vec3
WhatPartOfALivesInBDir( glm::vec3 a, glm::vec3 b )
{
	float dot_product;
    glm::vec3 bhat;

    bhat = glm::normalize(b);
    dot_product = glm::dot(a, bhat);

    return(dot_product * bhat);
}


glm::vec3
WhatPartOfALivesPerpToB( glm::vec3 a, glm::vec3 b )
{
    return(a - WhatPartOfALivesInBDir(a, b));
}


glm::vec3
UnitSurfaceNormal( glm::vec3 q, glm::vec3 r, glm::vec3 s )
{
    glm::vec3 vector1;
    glm::vec3 vector2;

    vector1 = r - q;
    vector2 = s - q;

    return(glm::normalize(glm::cross(vector1, vector2)));
}

// WORKING
float
Area( glm::vec3 q, glm::vec3 r, glm::vec3 s )
{
    glm::vec3 vector1;
    glm::vec3 vector2;

    vector1 = r - q;
    vector2 = s - q;

    return(0.5 * glm::length(glm::cross(vector1, vector2)));
}

bool
IsPointInTriangle( glm::vec3 q, glm::vec3 r, glm::vec3 s, glm::vec3 p )
{
    glm::vec3 n = glm::cross((r-q), (s-q));
    glm::vec3 nq = glm::cross((r-q), (p-q));
    glm::vec3 nr = glm::cross((s-r), (p-r));
    glm::vec3 ns = glm::cross((q-s), (p-s));

    float nnq = glm::dot(n, nq);
    float nnr = glm::dot(n, nr);
    float nns = glm::dot(n, ns);

    if(nnq <= 0.)
    {
        return(false);
    }
    if(nnr <= 0.)
    {
        return(false);
    }
    if(nns <= 0.)
    {
        return(false);
    }
}



float
DistanceFromPointToPlane( glm::vec3 q, glm::vec3 r, glm::vec3 s, glm::vec3 p )
{
    return glm::dot((p - q), glm::normalize(glm::cross(r, s)));
}


void
WhoAmI( std::string &yourName, std::string &yourEmailAddress )
{
	yourName = "Srikar Valluri";
	yourEmailAddress = "valluris@oregonstate.edu" ;
}

