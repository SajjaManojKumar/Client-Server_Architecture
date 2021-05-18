#include<windows.h>
#include <string.h>
#include <GL/glut.h>
#include <string>

using namespace std;

//void *font = GLUT_BITMAP_HELVETICA_18;
// Screen Size 500, 300
int screenX = 750, screenY = 450;
char screenTitle[] = "Client-Server Architecture";
char defaultMessage1[] = "[404] : Default message1", defaultMessage2[] = "[404] : Default message2", defaultMessage3[] = "[404] : Default message3";
char *message1 = defaultMessage1, *message2 = defaultMessage2, *message3 = defaultMessage3;
int msgCount = 0;
char pressAny[] = "[404] : Default pressAnyMsg";
char *pressAnyMsg = pressAny;
bool connectionUser1 = false, connectionUser2 = false, connectionUser3 = false;
bool User1ToUser2 = false, User1ToUser3 = false, User2ToUser1 = false, User2ToUser3 = false, User3ToUser1 = false, User3ToUser2 = false;
int user1PacketPos = 0, user2PacketPos = 0, user3PacketPos = 0;

// Function
void selectState(int msg);
void display(void);
void reshape(int w, int h);
void tick(void);
void output(int x, int y, char *str, void *font);
void keyboard(unsigned char key, int _, int __);
void selectConnectionUser1(int num);
void selectConnectionUser2(int num);
void selectConnectionUser3(int num);
void sendDataUser1(int num);
void sendDataUser2(int num);
void sendDataUser3(int num);
void selectAction(int num);
void funcDisplay(void);
void drawRectangle(int x1, int y1, int x, int y, int r, int g, int b);
void drawLine(int x1,int y1, int x2, int y2, int thickness);
void sendHelloPacket(int x1, int y1, int x2, int y2);
void packet(int x, int y, int r, int g, int b);


// To select the current state of the application.
void selectState(int msg){
  switch (msg) {
    case 0:
        message1 = "Sorry something went wrong";
        message2 = "";
        message3 = "Press N to restart";
        pressAnyMsg = "";
        break;
    case 1:
        message1 = "NMAM Institute of Technology";
        message2 = "Subject:- Computer Graphics";
        message3 = "Faculty:- Puneeth R P";
        pressAnyMsg = "(---Press 'N' for Next---)";
        break;
    case 2:
        message1 = "Client-Server Architecture";
        message2 = "";
        message3 = "By:- Pratheeksha P & Manoj Kumar Sajja";
        pressAnyMsg = "(---Press 'N' for Next and 'B' for Back---)";
        break;
    case 3:
        message1 = "The following project is";
        message2 = "used to illustrate few of the";
        message3 = "actions between client and server.";
        pressAnyMsg = "(---Press 'N' for Next and 'B' for Back---)";
        break;
    case 4:
        message1 = "On right-click, you get to choose users.";
        message2 = "Each user has 3 options. Establish, disconnect & send data.";
        message3 = "Establish and disconnect will connect with server and disconnect.";
        pressAnyMsg = "(---Press 'N' for Next and 'B' for Back---)";
        glutAttachMenu(GLUT_RIGHT_BUTTON);
        break;
    case 5:
        message1 = "Send data option will send data to other users.";
        message2 = "To stop sending data between users, choose same option again.";
        message3 = "Packets are sent between connections and received.";
        pressAnyMsg = "(---Press 'N' for Next and 'B' for Back---)";
        glutAttachMenu(GLUT_RIGHT_BUTTON);
        break;
    case 6:
        message1 = "";
        message2 = "";
        message3 = "";
        pressAnyMsg = "";
        glutAttachMenu(GLUT_RIGHT_BUTTON);

        break;
    case 7:
        message1 = "";
        message2 = "Press 'E' To Exit";
        message3 = "";
        pressAnyMsg = "Thank You";
        break;
    default:
        exit(0);
  }
}

// Default display function
void display(void){
  glClear(GL_COLOR_BUFFER_BIT);
<<<<<<< HEAD
  output((screenX/2 - ((strlen(message1)/2)*10)), (int)(screenY/2 - 20), message1, GLUT_BITMAP_HELVETICA_18);
  output((screenX/2 - ((strlen(message2)/2)*10)), (int)(screenY/2), message2, GLUT_BITMAP_HELVETICA_18);
  output((screenX/2 - ((strlen(message3)/2)*10)), (int)(screenY/2 + 20), message3, GLUT_BITMAP_HELVETICA_18);
  output((screenX/2 - ((strlen(pressAnyMsg)/2)*10)), (int)screenY*0.9, pressAnyMsg, GLUT_BITMAP_8_BY_13);
=======
  output((screenX/2 - ((strlen(message1)/2)*9)), (int)(screenY/2 - 20), message1, GLUT_BITMAP_HELVETICA_18);
  output((screenX/2 - ((strlen(message2)/2)*9)), (int)(screenY/2), message2, GLUT_BITMAP_HELVETICA_18);
  output((screenX/2 - ((strlen(message3)/2)*9)), (int)(screenY/2 + 20), message3, GLUT_BITMAP_HELVETICA_18);
  output((screenX/2 - ((strlen(pressAnyMsg)/2)*9)), (int)screenY*0.9, pressAnyMsg, GLUT_BITMAP_8_BY_13);
>>>>>>> 11cd89f43f5636bf5e18be41f8fa6259578dc2f4
  if(msgCount == 6){
        funcDisplay();
  }
  glutSwapBuffers();
}

// Function called when size of screen is resized
void reshape(int w, int h){
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, w, h, 0);
  screenX = w;
  screenY = h;
}

// Function called when system is ideal
void tick(void){
  glutPostRedisplay();
}

// Function to print message on screen
void output(int x, int y, char *str, void *font){
  int len, i;
  glRasterPos2f(x, y);
  len = (int) strlen(str);
  for (i = 0; i < len; i++) {
  glutBitmapCharacter(font, str[i]);
  }
}

// KeyBoard Function
void keyboard(unsigned char key, int _, int __) {
  if((key == 'n' || key == 'N') && msgCount < 7){
    selectState(++msgCount);
  }
  else if((key == 'b' || key == 'B') && msgCount > 1){
    selectState(--msgCount);
  }
  else if((key == 'e' || key == 'E') && msgCount == 7){
    selectState(++msgCount);
  }
  else{
    --msgCount;
    selectState(0);
  }
}



// Function to select the state of connection ( Connect , Disconnect )
void selectConnectionUser1(int num){
    switch(num){
        case 1: // Establish
            if(msgCount== 6){
                connectionUser1 = true;
            }
            break;
        case 0: // Disconnect
            connectionUser1 = false;
            break;
    }
}

// Function to select the state of connection ( Connect , Disconnect )
void selectConnectionUser2(int num){
    switch(num){
        case 1: // Establish
            if(msgCount== 6){
                connectionUser2 = true;
            }
            break;
        case 0: // Disconnect
            connectionUser2 = false;
            break;
    }
}

// Function to select the state of connection ( Connect , Disconnect )
void selectConnectionUser3(int num){
    switch(num){
        case 1: // Establish
            if(msgCount== 6){
                connectionUser3 = true;
            }
            break;
        case 0: // Disconnect
            connectionUser3 = false;
            break;
    }
}

// Function to send data from User 1
void sendDataUser1(int num){
    switch(num){
        case 2:
            if(User1ToUser2) User1ToUser2=false;
            else User1ToUser2 = true;
            break;
        case 3:
            if(User1ToUser3) User1ToUser3=false;
            else User1ToUser3 = true;
            break;
    }
}

// Function to send data from User 2
void sendDataUser2(int num){
    switch(num){
        case 1:
            if(User2ToUser1) User2ToUser1=false;
            else User2ToUser1 = true;
            break;
        case 3:
            if(User2ToUser3) User2ToUser3=false;
            else User2ToUser3 = true;
            break;
    }
}

// Function to send data from User 3
void sendDataUser3(int num){
    switch(num){
        case 1:
            if(User3ToUser1) User3ToUser1=false;
            else User3ToUser1 = true;
            break;
        case 2:
            if(User3ToUser2) User3ToUser2=false;
            else User3ToUser2 = true;
            break;
    }
}

// Call back function for menu
void selectAction(int num){
    switch(num){
        case 0: // Disconnect
            msgCount = 4;
            break;
        case 1:
            msgCount = 7;
            break;
    }
    selectState(msgCount);
}

// Function to draw Server/Client. Called at state 6.
void funcDisplay(void){
    // User 1
  drawRectangle(((screenX * 0.75) - 25), ((screenY * 0.15) - 25), 50, 50, 1, 0, 0);
  output(((screenX * 0.75) - 25), ((screenY * 0.15) - 28), "User 1", GLUT_BITMAP_9_BY_15);
    // User 2
  drawRectangle(((screenX * 0.75) - 25), ((screenY * 0.35) - 25), 50, 50, 0, 1, 0);
  output(((screenX * 0.75) - 25), ((screenY * 0.35)- 28), "User 2", GLUT_BITMAP_9_BY_15);
    // User 3
  drawRectangle(((screenX * 0.75) - 25), ((screenY * 0.7) - 25), 50, 50, 1, 1, 0);
  output(((screenX * 0.75) - 25), ((screenY * 0.7) - 28), "User 3", GLUT_BITMAP_9_BY_15);

    // Server 1
  drawRectangle(((screenX * 0.25) - 30), ((screenY * 0.25) - 80), 60, 160, 1, 1, 1);
  output(((screenX * 0.25) - 110), (screenY * 0.25), "Server 1", GLUT_BITMAP_9_BY_15);
    // Server 2
  drawRectangle(((screenX * 0.25) - 30), ((screenY * 0.7) - 80), 60, 160, 1, 1, 1);
  output(((screenX * 0.25) - 110), (screenY * 0.7), "Server 2", GLUT_BITMAP_9_BY_15);
    // Connection b/w Server 1 and Sever 2
  drawLine((screenX * 0.25), ((screenY * 0.25) + 80), (screenX * 0.25), ((screenY * 0.7) - 80), 5);

    // Connection b/w User 1, User 2 and Server 1 & User 3 andSever 2
    if(connectionUser1){
        drawLine(((screenX * 0.75) - 25), (screenY * 0.15), ((screenX * 0.25) + 30), (screenY * 0.15), 2);
        if(((screenX * 0.75) - 40 - user1PacketPos) < ((screenX * 0.25) + 30))user1PacketPos = 0;
        packet(((screenX * 0.75) - 40 - user1PacketPos), ((screenY * 0.15) - 15), 1, 0, 0); // User 1 -> Server 1
        packet(((screenX * 0.25) + 45 + user1PacketPos), ((screenY * 0.15) + 15), 1, 1, 1); // Server 1 -> User 1
        user1PacketPos++;
    }
    if(connectionUser2){
        drawLine(((screenX * 0.75) - 25), (screenY * 0.35), ((screenX * 0.25) + 30), (screenY * 0.35), 2);
        if(((screenX * 0.75) - 40 - user2PacketPos) < ((screenX * 0.25) + 30))user2PacketPos = 0;
        packet(((screenX * 0.75) - 40 - user2PacketPos), ((screenY * 0.35) - 15), 0, 1, 0); // User 2 -> Server 1
        packet(((screenX * 0.25) + 45 + user2PacketPos), ((screenY * 0.35) + 15), 1, 1, 1); // Server 1 -> User 2
        user2PacketPos++;
    }
    if(connectionUser3){
        drawLine(((screenX * 0.75) - 25), (screenY * 0.70), ((screenX * 0.25) + 30), (screenY * 0.7), 2);
        if(((screenX * 0.75) - 40 - user3PacketPos) < ((screenX * 0.25) + 30))user3PacketPos = 0;
        packet(((screenX * 0.75) - 40 - user3PacketPos), ((screenY * 0.7) - 15), 1, 1, 0); // User 3 -> Server 2
        packet(((screenX * 0.25) + 45 + user3PacketPos), ((screenY * 0.7) + 15), 1, 1, 1); // Server 2 -> User 3
        user3PacketPos++;
    }
    if(User1ToUser2){
        drawLine(((screenX * 0.75) - 25), (screenY * 0.15), ((screenX * 0.25) + 30), (screenY * 0.15), 2);
        drawLine(((screenX * 0.75) - 25), (screenY * 0.35), ((screenX * 0.25) + 30), (screenY * 0.35), 2);
        if(((screenX * 0.75) - 40 - user1PacketPos) < ((screenX * 0.25) + 30))user1PacketPos = 0;
        if(((screenX * 0.75) - 40 - user2PacketPos) < ((screenX * 0.25) + 30))user2PacketPos = 0;
        packet(((screenX * 0.75) - 40 - user1PacketPos), ((screenY * 0.15) - 15), 1, 0, 0); // User 1 -> Server 1
        packet(((screenX * 0.25) + 45 + user2PacketPos), ((screenY * 0.35) + 15), 1, 0, 0); // Server 1 -> User 2
        user1PacketPos++;
        user2PacketPos++;
    }
    if(User1ToUser3){
        drawLine(((screenX * 0.75) - 25), (screenY * 0.15), ((screenX * 0.25) + 30), (screenY * 0.15), 2);
        drawLine(((screenX * 0.75) - 25), (screenY * 0.70), ((screenX * 0.25) + 30), (screenY * 0.7), 2);
        if(((screenX * 0.75) - 40 - user1PacketPos) < ((screenX * 0.25) + 30))user1PacketPos = 0;
        if(((screenX * 0.75) - 40 - user3PacketPos) < ((screenX * 0.25) + 30))user3PacketPos = 0;
        packet(((screenX * 0.75) - 40 - user1PacketPos), ((screenY * 0.15) - 15), 1, 0, 0); // User 1 -> Server 1
        packet(((screenX * 0.25) + 45 + user3PacketPos), ((screenY * 0.7) + 15), 1, 0, 0); // Server 2 -> User 3
        user1PacketPos++;
        user3PacketPos++;
    }
    if(User2ToUser1){
        drawLine(((screenX * 0.75) - 25), (screenY * 0.35), ((screenX * 0.25) + 30), (screenY * 0.35), 2);
        drawLine(((screenX * 0.75) - 25), (screenY * 0.15), ((screenX * 0.25) + 30), (screenY * 0.15), 2);
        if(((screenX * 0.75) - 40 - user2PacketPos) < ((screenX * 0.25) + 30))user2PacketPos = 0;
        if(((screenX * 0.75) - 40 - user1PacketPos) < ((screenX * 0.25) + 30))user1PacketPos = 0;
        packet(((screenX * 0.75) - 40 - user2PacketPos), ((screenY * 0.35) - 15), 0, 1, 0); // User 2 -> Server 1
        packet(((screenX * 0.25) + 45 + user1PacketPos), ((screenY * 0.15) + 15), 0, 1, 0); // Server 1 -> User 1
        user2PacketPos++;
        user1PacketPos++;
    }
    if(User2ToUser3){
        drawLine(((screenX * 0.75) - 25), (screenY * 0.35), ((screenX * 0.25) + 30), (screenY * 0.35), 2);
        drawLine(((screenX * 0.75) - 25), (screenY * 0.70), ((screenX * 0.25) + 30), (screenY * 0.7), 2);
        if(((screenX * 0.75) - 40 - user2PacketPos) < ((screenX * 0.25) + 30))user2PacketPos = 0;
        if(((screenX * 0.75) - 40 - user3PacketPos) < ((screenX * 0.25) + 30))user3PacketPos = 0;
        packet(((screenX * 0.75) - 40 - user2PacketPos), ((screenY * 0.35) - 15), 0, 1, 0); // User 2 -> Server 1
        packet(((screenX * 0.25) + 45 + user3PacketPos), ((screenY * 0.7) + 15), 0, 1, 0); // Server 2 -> User 3
        user2PacketPos++;
        user3PacketPos++;
    }
    if(User3ToUser1){
        drawLine(((screenX * 0.75) - 25), (screenY * 0.70), ((screenX * 0.25) + 30), (screenY * 0.7), 2);
        drawLine(((screenX * 0.75) - 25), (screenY * 0.15), ((screenX * 0.25) + 30), (screenY * 0.15), 2);
        if(((screenX * 0.75) - 40 - user3PacketPos) < ((screenX * 0.25) + 30))user3PacketPos = 0;
        if(((screenX * 0.75) - 40 - user1PacketPos) < ((screenX * 0.25) + 30))user1PacketPos = 0;
        packet(((screenX * 0.75) - 40 - user3PacketPos), ((screenY * 0.7) - 15), 1, 1, 0); // User 3 -> Server 2
        packet(((screenX * 0.25) + 45 + user1PacketPos), ((screenY * 0.15) + 15), 1, 1, 0); // Server 1 -> User 1
        user3PacketPos++;
        user1PacketPos++;
    }
    if(User3ToUser2){
        drawLine(((screenX * 0.75) - 25), (screenY * 0.70), ((screenX * 0.25) + 30), (screenY * 0.7), 2);
        drawLine(((screenX * 0.75) - 25), (screenY * 0.35), ((screenX * 0.25) + 30), (screenY * 0.35), 2);
        if(((screenX * 0.75) - 40 - user3PacketPos) < ((screenX * 0.25) + 30))user3PacketPos = 0;
        if(((screenX * 0.75) - 40 - user2PacketPos) < ((screenX * 0.25) + 30))user2PacketPos = 0;
        packet(((screenX * 0.75) - 40 - user3PacketPos), ((screenY * 0.7) - 15), 1, 1, 0); // User 3 -> Server 2
        packet(((screenX * 0.25) + 45 + user2PacketPos), ((screenY * 0.35) + 15), 1, 1, 0); // Server 1 -> User 2
        user3PacketPos++;
        user2PacketPos++;
    }
}

// Function to draw Rectangle for Server/Client
void drawRectangle(int x1, int y1, int x, int y, int r, int g, int b){
     glColor3f(r, g, b);
     glBegin(GL_POLYGON);
     glVertex2f(x1+10,y1+10);
     glVertex2f(x1+x-10,y1+10);
     glVertex2f(x1+x-10,y1+y-10);
     glVertex2f(x1+10,y1+y-10);
     glEnd();

     glColor3f(1, 1, 1);
     glBegin(GL_LINE_LOOP);
     glVertex2f(x1,y1);
     glVertex2f(x1+x,y1);
     glVertex2f(x1+x,y1+y);
     glVertex2f(x1,y1+y);
     glEnd();
}

// Function to draw line
void drawLine(int x1,int y1, int x2, int y2, int thickness) {
    glLineWidth(thickness);
    glBegin(GL_LINES);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glEnd();
    glLineWidth(1);
}

// Function to generate packet
void packet(int x,int y, int r, int g, int b) {
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    glVertex2f(x-9,y-9);
    glVertex2f(x-9,y+9);
    glVertex2f(x+9,y+9);
    glVertex2f(x+9,y-9);
    glEnd();
    glColor3f(1, 1, 1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x-10,y-10);
    glVertex2f(x-10,y+10);
    glVertex2f(x+10,y+10);
    glVertex2f(x+10,y-10);
    glEnd();
}


// Main Function
int main(int argc, char **argv){
  int connectionSubMenuUser1, connectionSubMenuUser2, connectionSubMenuUser3;
  int sendDataSubMenuUser1, sendDataSubMenuUser2, sendDataSubMenuUser3;

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(screenX, screenY);
  glutCreateWindow(screenTitle);
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutIdleFunc(tick);

  selectState(++msgCount);
  glutKeyboardFunc(keyboard);

  sendDataSubMenuUser1 = glutCreateMenu(sendDataUser1);
  glutAddMenuEntry("User 2", 2);
  glutAddMenuEntry("User 3", 3);

  sendDataSubMenuUser2 = glutCreateMenu(sendDataUser2);
  glutAddMenuEntry("User 1", 1);
  glutAddMenuEntry("User 3", 3);

  sendDataSubMenuUser3 = glutCreateMenu(sendDataUser3);
  glutAddMenuEntry("User 1", 1);
  glutAddMenuEntry("User 2", 2);

  connectionSubMenuUser1 = glutCreateMenu(selectConnectionUser1);
  glutAddMenuEntry("Establish", 1);
  glutAddMenuEntry("Disconnect", 0);
  glutAddSubMenu("Send Data", sendDataSubMenuUser1);

  connectionSubMenuUser2 = glutCreateMenu(selectConnectionUser2);
  glutAddMenuEntry("Establish", 1);
  glutAddMenuEntry("Disconnect", 0);
  glutAddSubMenu("Send Data", sendDataSubMenuUser2);

  connectionSubMenuUser3 = glutCreateMenu(selectConnectionUser3);
  glutAddMenuEntry("Establish", 1);
  glutAddMenuEntry("Disconnect", 0);
  glutAddSubMenu("Send Data", sendDataSubMenuUser3);

  glutCreateMenu(selectAction);
  glutAddMenuEntry("About", 0);
  glutAddSubMenu("User 1", connectionSubMenuUser1);
  glutAddSubMenu("User 2", connectionSubMenuUser2);
  glutAddSubMenu("User 3", connectionSubMenuUser3);
  glutAddMenuEntry("Exit", 1);

  glutMainLoop();
  return 0;
}
