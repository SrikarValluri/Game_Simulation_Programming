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
    dot_product = glm::dot(a, b);

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

    return(glm::cross(vector1, vector2));

}


float
Area( glm::vec3 q, glm::vec3 r, glm::vec3 s )
{
    return(0.5 * glm::length(UnitSurfaceNormal(q, r, s)));
}


bool
IsPointInTriangle( glm::vec3 q, glm::vec3 r, glm::vec3 s, glm::vec3 p )
{
    float Ers;
    float Esq;
    float Eqr;

    Ers = glm::dot((p - r), glm::vec3(r.y-s.y, s.x-r.x, 0));
    Esq = glm::dot((p - s), glm::vec3(s.y-q.y, q.x-s.x, 0));
    Eqr = glm::dot((p - q), glm::vec3(q.y-r.y, r.x-q.x, 0));

    if(Ers > 0. && Esq > 0. && Eqr > 0.)
    {
        return true;
    }
    else
    {
        return false;
    }
}



float
DistanceFromPointToPlane( glm::vec3 q, glm::vec3 r, glm::vec3 s, glm::vec3 p )
{
    return glm::dot((p - q), UnitSurfaceNormal(q, r, s));
}


void
WhoAmI( std::string &yourName, std::string &yourEmailAddress )
{
	yourName = "Srikar Valluri";
	yourEmailAddress = "valluris@oregonstate.edu" ;
}


int main(){
    return 0;
}