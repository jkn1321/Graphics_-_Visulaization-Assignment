#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <math.h>

//Positions and scales
float horsePositionX = 0.0f;
float horaseAngle = 0.0f;
float tailAngle = 0.0f;
float boatPositionX = 0.0f;
float boatBatPositionX = 0.0f;
float flowerPotScaleToLarge = 1.0f;
float flowerPotScaleToSmall1 = 1.0f;
float flowerPotScaleToSmall2 = 1.0f;
float fishScale = 1.0f;
float flowersScale = 1.0f;
float sunPositionX = 0.0f;


//Top part of the scene

//Garden
void drawGarden(){
    glColor3f(0.14f, 0.56f, 0.15f); //Green color
    glBegin(GL_POLYGON);
    glVertex2f(-1.0f, -0.23f);
    glVertex2f(-0.58f, -0.08f);
    glVertex2f(-0.35f, -0.08f);
    glVertex2f(1.0f, -0.23f);
    glVertex2f(1.0f, -0.52f);
    glVertex2f(-1.0f, -0.52f);
    glEnd();
}


//Sun
void drawSun(){
    glPushMatrix();
    glTranslatef(sunPositionX, 0.0f, 0.0f);
    float theta;

    glColor3f(0.93f, 0.5f, 0.04f);  //Orange color
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++){
        theta = i*3.142/180;
        glVertex2f(0.9 + 0.08*cos(theta),0.7 + 0.13*sin(theta));
    }
    glEnd();
    glPopMatrix();
}


//Left side house
void drawLeftHouse(){
    //Left house body
    glColor3f(0.43f, 0.12f, 0.59f); //Dark purple color
    glBegin(GL_POLYGON);
    glVertex2f(-0.58f, 0.21f);
    glVertex2f(-0.35f, 0.21f);
    glVertex2f(-0.35f, -0.1f);
    glVertex2f(-0.58f, -0.1f);
    glEnd();

    //Left house roof
    glColor3f(1.0f, 0.0f, 0.0f);  //Red color
    glBegin(GL_POLYGON);
    glVertex2f(-0.57f, 0.29f);
    glVertex2f(-0.36f, 0.29f);
    glVertex2f(-0.33f, 0.21f);
    glVertex2f(-0.6f, 0.21f);
    glEnd();

    //Left House door
    glColor3f(0.84f, 0.66f, 0.21f); //Light orange color
    glBegin(GL_POLYGON);
    glVertex2f(-0.5f, 0.08f);
    glVertex2f(-0.43f, 0.08f);
    glVertex2f(-0.43f, -0.1f);
    glVertex2f(-0.5f, -0.1f);
    glEnd();
}

//Right side house
void drawRightHouse(){
    //Right house body
    glColor3f(0.75f, 0.29f, 0.54f); //Dark pink color
    glBegin(GL_POLYGON);
    glVertex2f(0.12f, 0.14f);
    glVertex2f(0.35f, 0.14f);
    glVertex2f(0.35f, -0.17f);
    glVertex2f(0.12f, -0.17f);
    glEnd();

    //Right house roof
    glColor3f(1.0f, 0.0f, 0.0f);  //Red color
    glBegin(GL_POLYGON);
    glVertex2f(0.13f, 0.22f);
    glVertex2f(0.34f, 0.22f);
    glVertex2f(0.37f, 0.14f);
    glVertex2f(0.1f, 0.14f);
    glEnd();

    //Right House door
    glColor3f(0.84f, 0.66f, 0.21f); //Light orange color
    glBegin(GL_POLYGON);
    glVertex2f(0.2f, 0.01f);
    glVertex2f(0.27f, 0.01f);
    glVertex2f(0.27f, -0.17f);
    glVertex2f(0.2f, -0.17f);
    glEnd();
}


//Left tree
void drawLeftTree(){
    //Bottom Triangle
    glColor3f(0.14f, 0.56f, 0.15f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.86f, 0.2f);
    glVertex2f(-0.72f, -0.12f);
    glVertex2f(-1.0f, -0.12f);
    glEnd();

    //Middle triangle
    glColor3f(0.14f, 0.56f, 0.15f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.86f,0.29f);
    glVertex2f(-0.75f, 0.08f);
    glVertex2f(-0.97f, 0.08f);
    glEnd();

    //Top triangle
    glColor3f(0.14f, 0.56f, 0.15f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.86f, 0.44f);
    glVertex2f(-0.78f, 0.23f);
    glVertex2f(-0.94f, 0.23f);
    glEnd();

    //Trunk
    glColor3f(0.45f, 0.18f, 0.1f); //Brown color
    glBegin(GL_POLYGON);
    glVertex2f(-0.88f, -0.12f);
    glVertex2f(-0.84f, -0.12f);
    glVertex2f(-0.84f, -0.35f);
    glVertex2f(-0.88f, -0.35f);
    glEnd();
}

//Middle tree
void drawMiddleTree(){
    glPushMatrix();
    glTranslatef(0.71f, 0.2f, 0.0f);
    drawLeftTree();
    glPopMatrix();

}

//Middle tree's left side tree fruit
void drawTreeFruit(){
    //stem
    glColor3f(0.45f, 0.18f, 0.1f); //Brown color
    glBegin(GL_POLYGON);
    glVertex2f(-0.22f, 0.08f);
    glVertex2f(-0.23f, 0.08f);
    glVertex2f(-0.23f, 0.03f);
    glVertex2f(-0.22f, 0.03f);
    glEnd();

    //Fruit
    float theta;

    glColor3f(1.0f, 0.0f, 0.0f);  //Red color
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++){
        theta = i*3.142/180;
        glVertex2f(-0.225 + 0.015*cos(theta),0.035 + 0.025*sin(theta));
    }
    glEnd();
}

//Middle tree's right side tree fruit
void drawMiddle2TreeFruit(){
    glPushMatrix();
    glTranslatef(0.15f, 0.0f, 0.0f);
    drawTreeFruit();
    glPopMatrix();
}

//Right tree
void drawRightTree(){

    glPushMatrix();
    glTranslatef(1.3f, 0.17f, 0.0f);
    drawLeftTree();
    glPopMatrix();
}

//Middle tree's left side tree fruit
void drawRight1TreeFruit(){
    glPushMatrix();
    glTranslatef(0.6f, -0.03f, 0.0f);
    drawTreeFruit();
    glPopMatrix();
}

//Right tree's right side tree fruit
void drawRight2TreeFruit(){
    glPushMatrix();
    glTranslatef(0.74f, -0.03f, 0.0f);
    drawTreeFruit();
    glPopMatrix();
}


//Flower pot
void drawFlowerPot(){
    //Pot
    glColor3f(0.93f, 0.5f, 0.04f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.79f, -0.36f);
    glVertex2f(-0.74f, -0.36f);
    glVertex2f(-0.75f, -0.45f);
    glVertex2f(-0.78f, -0.45f);
    glEnd();

    //Flowers
    //Middle stem
    glColor3f(0.74f, 0.53f, 0.31f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.77f, -0.27f);
    glVertex2f(-0.76f, -0.27f);
    glVertex2f(-0.76f, -0.36f);
    glVertex2f(-0.77f, -0.36f);
    glEnd();

    //Right stem
    glColor3f(0.74f, 0.53f, 0.31f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.77f, -0.29f);
    glVertex2f(-0.73f, -0.27f);
    glVertex2f(-0.73f, -0.28f);
    glVertex2f(-0.76f, -0.30f);
    glEnd();

    //Left stem
    glColor3f(0.74f, 0.53f, 0.31f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.8f, -0.32f);
    glVertex2f(-0.8f, -0.33f);
    glVertex2f(-0.77f, -0.34f);
    glVertex2f(-0.77f, -0.33f);
    glEnd();

    //Red flower
    float theta;

    glColor3f(1.0f, 0.0f, 0.0f);  //Red color
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++){
        theta = i*3.142/180;
        glVertex2f(-0.81 + 0.015*cos(theta),-0.32 + 0.025*sin(theta)); // Centre position(-0.81f, -0.32f)
    }
    glEnd();

    //Light pink flower
    glColor3f(0.94f, 0.58f, 0.82f);  //Light pink color
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++){
        theta = i*3.142/180;
        glVertex2f(-0.765 + 0.015*cos(theta),-0.247 + 0.025*sin(theta)); // Centre position(-0.765f, -0.247f)
    }
    glEnd();

    //Light Purple flower
    glColor3f(0.78f, 0.4f, 0.88f);  //Light Purple color
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++){
        theta = i*3.142/180;
        glVertex2f(-0.73 + 0.015*cos(theta),-0.27 + 0.025*sin(theta)); // Centre position(-0.73f, -0.27f)
    }
    glEnd();
}

//Left side 1st flower pot
void drawLeft1FlowerPot(float x, float y){
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(flowerPotScaleToLarge, flowerPotScaleToLarge, 1.0f);
    glTranslatef(-x, -y, 0.0f);
    drawFlowerPot();
    glPopMatrix();
}

//Left side 2nd flower pot
void drawLeft2FlowerPot(float x, float y){
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(flowerPotScaleToLarge, flowerPotScaleToLarge, 1.0f);
    glTranslatef(-x, -y, 0.0f);
    glTranslatef(0.15f, 0.08f, 0.0f);
    drawFlowerPot();
    glPopMatrix();
}

//Right side small(1st) flower pot
void drawRightSmallFlowerPot(float x, float y){
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(flowerPotScaleToSmall1, flowerPotScaleToSmall1, 1.0f);
    glTranslatef(-x, -y, 0.0f);
    glTranslatef(1.35f, -0.03f, 0.0f);
    drawFlowerPot();
    glPopMatrix();
}

//Right side big(2nd) flower pot
void drawRightBigFlowerPot(float x, float y){
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(flowerPotScaleToSmall1, flowerPotScaleToSmall1, 1.0f);
    glTranslatef(-x, -y, 0.0f);
    glTranslatef(x, y, 0.0f);
    glScalef(flowerPotScaleToSmall2, flowerPotScaleToSmall2, 1.0f);
    glTranslatef(-x, -y, 0.0f);
    glTranslatef(2.28f, 0.38f, 0.0f);
    glScalef(2.0f, 2.0f, 0.0f);
    drawFlowerPot();
    glPopMatrix();
}


//Horse
void drawHorse(float x, float y){
    glPushMatrix();
    glTranslatef(horsePositionX, 0.0f, 0.0f);
    glTranslatef(x, y, 0.0f);
    glRotatef(horaseAngle, 0.0f, 1.0f, 0.0f);
    glTranslatef(-x, -y, 0.0f);
    //body
    glColor3f(0.78f, 0.3f, 0.13f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.26f, -0.23f);
    glVertex2f(-0.12f, -0.23f);
    glVertex2f(-0.12f, -0.33f);
    glVertex2f(-0.26f, -0.33f);
    glEnd();

    //Head
    glColor3f(0.78f, 0.3f, 0.13f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.33f, -0.1f);
    glVertex2f(-0.26f, -0.1f);
    glVertex2f(-0.24f, -0.23f);
    glVertex2f(-0.26f, -0.23f);
    glVertex2f(-0.27f, -0.2f);
    glVertex2f(-0.33f, -0.14f);
    glEnd();

    //Head top part
    glColor3f(0.78f, 0.3f, 0.13f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.274f, -0.01f);
    glVertex2f(-0.26f, -0.1f);
    glVertex2f(-0.31f, -0.1f);
    glEnd();

    //Mouth line
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.31f, -0.1f);
    glVertex2f(-0.31f, -0.16f);
    glEnd();

    //Hair
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.274f, -0.01f);
    glVertex2f(-0.2f, -0.23f);
    glVertex2f(-0.24f, -0.23f);
    glEnd();

    //Eye
    float theta;

    glColor3f(0.0f, 0.0f, 0.0f);  //black color
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++){
        theta = i*3.142/180;
        glVertex2f(-0.285 + 0.004*cos(theta), -0.07 + 0.006*sin(theta)); // Centre position(-0.285f, -0.07f)
    }
    glEnd();

    //Left leg
    glColor3f(1.0f, 1.0f, 1.0f);  //White color
    glBegin(GL_POLYGON);
    glVertex2f(-0.26f, -0.33f);
    glVertex2f(-0.245f, -0.33f);
    glVertex2f(-0.245f, -0.42f);
    glVertex2f(-0.26f, -0.42f);
    glEnd();

    //Right leg
    glColor3f(1.0f, 1.0f, 1.0f);  //White color
    glBegin(GL_POLYGON);
    glVertex2f(-0.135f, -0.33f);
    glVertex2f(-0.12f, -0.33f);
    glVertex2f(-0.12f, -0.42f);
    glVertex2f(-0.135f, -0.42f);
    glEnd();

    //Tail
    glPushMatrix();
    glTranslatef(-0.12f, -0.23f, 0.0f);
    glRotatef(tailAngle, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.12f, 0.23f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);            //White color
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.12f, -0.23f);
    glVertex2f(-0.1f, -0.23f);
    glVertex2f(-0.11f, -0.36f);
    glEnd();
    glPopMatrix();
}




//Bottom part of the scene


void drawRiver(){
    glColor3f(0.29f, 0.38f, 0.81f); //Blue Color
    glBegin(GL_POLYGON);
    glVertex2f(-1.0f, -0.52f);
    glVertex2f(1.0f, -0.52f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();
}


void drawBoat(){
    //Boat
    glPushMatrix();
    glTranslatef(boatPositionX, 0.0f, 0.0f);
    glColor3f(0.93f, 0.5f, 0.04f);          //Orange color
    glBegin(GL_POLYGON);
    glVertex2f(-0.6f, -0.65f);
    glVertex2f(-0.08f, -0.65f);
    glVertex2f(-0.13f, -0.8f);
    glVertex2f(-0.56f, -0.8f);
    glEnd();


    //Man
    //Man's top part of the body
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5f, -0.4f);
    glVertex2f(-0.43f, -0.4f);
    glVertex2f(-0.46f, -0.52f);
    glVertex2f(-0.5f, -0.52f);
    glEnd();

    //Man's bottom part of the body
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5f,-0.52f);
    glVertex2f(-0.42f, -0.52f);
    glVertex2f(-0.35f, -0.65f);
    glVertex2f(-0.5f, -0.65f);
    glEnd();

    //Man's top part of the head
    glColor3f(0.96f, 0.51f, 0.56f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.49f, -0.28f);
    glVertex2f(-0.45f, -0.28f);
    glVertex2f(-0.44f, -0.36f);
    glVertex2f(-0.49f, -0.36f);
    glEnd();

    //Man's bottom part of the head
    glColor3f(0.96f, 0.51f, 0.56f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.49f, -0.36f);
    glVertex2f(-0.45f, -0.36f);
    glVertex2f(-0.45f, -0.4f);
    glVertex2f(-0.49f, -0.4f);
    glEnd();

    //Man's hair
    glColor3f(0.0f, 0.0f, 0.0f); //Black color
    glBegin(GL_POLYGON);
    glVertex2f(-0.49f, -0.26f);
    glVertex2f(-0.44f, -0.24f);
    glVertex2f(-0.45f, -0.28f);
    glVertex2f(-0.49f, -0.28f);
    glEnd();


    //BoatPaddle
    glTranslatef(boatBatPositionX, 0.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.42f, -0.52f);
    glVertex2f(-0.55f, -0.85f);
    glVertex2f(-0.58f, -0.85f);
    glEnd();
    glPopMatrix();
}


//Fish
void drawFish(float bodyR, float bodyG, float bodyB, float finR, float finG, float finB){
    //Body of fish
    glColor3f(bodyR, bodyG, bodyB);
    glBegin(GL_POLYGON);
    glVertex2f(-0.86f, -0.67f);
    glVertex2f(-0.82f, -0.63f);
    glVertex2f(-0.78f, -0.67f);
    glVertex2f(-0.82f, -0.71f);
    glEnd();

    //Fish body first line (From left)
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f, -0.66f);
    glVertex2f(-0.85f, -0.68f);
    glEnd();

    //Fish body 2nd line (From left)
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.83f, -0.64f);
    glVertex2f(-0.83f, -0.7f);
    glEnd();

    //Fish body 3rd line (From left)
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.82f, -0.63f);
    glVertex2f(-0.82f, -0.71f);
    glEnd();

    //Fish eye
    float theta;

    glColor3f(0.0f, 0.0f, 0.0f);  //black color
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++){
        theta = i*3.142/180;
        glVertex2f(-0.8 + 0.004*cos(theta),-0.66 + 0.006*sin(theta)); // Centre position(-0.8f, -0.66f)
    }
    glEnd();

    //Top fin
    glColor3f(finR, finG, finB);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.84f, -0.6f);
    glVertex2f(-0.82f, -0.63f);
    glVertex2f(-0.83f, -0.64f);
    glEnd();

    //Bottom fin
    glColor3f(finR, finG, finB);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.83f, -0.7f);
    glVertex2f(-0.82f, -0.71f);
    glVertex2f(-0.84f, -0.74f);
    glEnd();

    //Back fin
    glColor3f(finR, finG, finB);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.89f, -0.63f);
    glVertex2f(-0.86f, -0.67f);
    glVertex2f(-0.89f, -0.71f);
    glEnd();
}

//Left side 1st yellow fish
void drawLeft1Fish(){
    glPushMatrix();
    drawFish(0.93f, 0.9f, 0.25f, 1.0f, 0.0f, 0.0f);  //bodyR, bodyG, bodyB, finR, finG, finB
    glPopMatrix();
}

//Left side 2nd yellow fish
void drawLeft2Fish(){
    glPushMatrix();
    glTranslatef(-1.53f, 0.08f, 0.0f);
    glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
    drawFish(0.93f, 0.9f, 0.25f, 1.0f, 0.0f, 0.0f);  //bodyR, bodyG, bodyB, finR, finG, finB
    glPopMatrix();
}

//Right side 1st yellow fish (From left)
void drawRight1Fish(float x, float y){
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(fishScale, fishScale, 1.0f);
    glTranslatef(-x, -y, 0.0f);
    glTranslatef(-0.72f, -0.1f, 0.0f);
    glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
    drawFish(0.0f, 0.0f, 1.0f, 0.93f, 0.27f, 0.74f);  //bodyR, bodyG, bodyB, finR, finG, finB
    glPopMatrix();
}

//Right side 2nd yellow fish (From left)
void drawRight2Fish(float x, float y){
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(fishScale, fishScale, 1.0f);
    glTranslatef(-x, -y, 0.0f);
    glTranslatef(-0.38f, 0.02f, 0.0f);
    glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
    drawFish(0.0f, 0.0f, 1.0f, 0.93f, 0.27f, 0.74f);  //bodyR, bodyG, bodyB, finR, finG, finB
    glPopMatrix();
}


void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    drawRiver();
    drawGarden();
    drawLeftHouse();
    drawRightTree();
    drawRightHouse();
    drawLeftTree();
    drawMiddleTree();
    drawTreeFruit();
    drawMiddle2TreeFruit();
    drawRight1TreeFruit();
    drawRight2TreeFruit();
    drawSun();
    drawLeft1FlowerPot(-0.78f, -0.45f);
    drawLeft2FlowerPot(-0.63f, -0.37f);
    drawRightSmallFlowerPot(0.57f, -0.48f);
    drawRightBigFlowerPot(0.72f, -0.52f);
    drawLeft1Fish();
    drawLeft2Fish();
    drawRight1Fish(0.14f, -0.77f);
    drawRight2Fish(0.48f, -0.65f);
    drawHorse(-0.26f, -0.23f);
    drawBoat();

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y){
    switch (key){
        case 'F':
        case 'f':
           horsePositionX -= 0.05f;  //Move horse to left
           if(horsePositionX < -1.0f){
                horsePositionX = 1.0f;  //Reset the position to right side when horse go out of the screen in left side
           }
           glutPostRedisplay();
           break;

        case 'R':
        case 'r':
            tailAngle -= 7.0f;      //Rotate the tail clockwise
            horsePositionX -= 0.01f;  //Move horse to left
            glutPostRedisplay();
            break;

        case 'Q':
        case 'q':
            horaseAngle = 180.0f;  //Rotate horse 180
            horsePositionX += 0.02f; //Move horse to right
            glutPostRedisplay();
            break;

        case 'B':
        case 'b':
            boatPositionX += 0.02f;  //Move boat to right
            glutPostRedisplay();
            break;

        case 'W':
        case 'w':
            boatPositionX += 0.02f;  //Move boat to right
            boatBatPositionX -= 0.01f;  //Move bat to left
            if(boatBatPositionX <- 0.03) {
                boatBatPositionX = 0.0;  //If the boat bat is out of man's body replace it to the it's original position
            }
            glutPostRedisplay();
            break;

        case 'U':
        case 'u':
            flowerPotScaleToLarge += 0.04f;
            fishScale += 0.02f;
            glutPostRedisplay();
            break;

        case 'S':
        case 's':
            flowerPotScaleToSmall1 -= 0.02f;
            glutPostRedisplay();
            break;

        case ' ':
            sunPositionX -= 0.02f;  //Move sun to left
            flowerPotScaleToSmall2 -= 0.02f;
            glutPostRedisplay();
            break;
    }
}


void init(){
    glClearColor(1.0f, 1.0f, 0.0f, 1.0f); //Set background color to yellow
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}



int main(int arc, char** argv){
    glutInit(&arc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1280, 760);
    glutCreateWindow("Village Scene");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
