#include <raylib.h>
#include<string>

class Ball
{
    public:
    float x,y,speedx,speedy,radius;
    
    void draw(){
        DrawCircle(x,y,radius,YELLOW);
    }
    
    void update(){
        x+=speedx;
        y+=speedy;
        if(y+radius>=GetScreenHeight() || y+radius<=0)
        speedy*=-1;
    }
    
    
};

class Box{
    public:
    float x,y,speedy,width,height;
    int score;
    
    void draw()
    {
        // DrawRectangle(x,y,width,height,WHITE);
        DrawRectangleRounded(Rectangle{x,y,width,height},0.8,0,WHITE);
    }
    
    
};


int main()
{
    const int screen_width=1280,screen_height=720;
    
    InitWindow(screen_width,screen_height,"ping pong");
    Color cyan ={20,160,133,255};
    SetTargetFPS(144);
    Texture2D img1 = LoadTexture("resources/img1.png"),img2=LoadTexture("resources/img2.png"),img3=LoadTexture("resources/img3.png");
    Texture2D img4= LoadTexture("resources/img4.png");
    int pain=1;
    Vector2 t1={315 - MeasureText("EASY MODE", 40)/2,360},t2={310 - MeasureText("EASY MODE", 40)/2,340},t3={310 - MeasureText("EASY MODE", 40)/2,380};
    
    
    
    Ball ball;
    ball.x=screen_width/2;
    ball.y=screen_height/2;
    ball.radius=20;
    Ball no_velocity_center=ball;
    
    
    Box box1,box2;
    box1.score=0,box2.score=0;
    box1.x=10;
    box1.width=20;
    box1.height=120;
    box1.y=screen_height/2-box1.height/2;
    box2.width=20;
    box2.x=screen_width-box2.width-10;
    box2.height=120;
    box2.y=screen_height/2-box2.height/2;
    
    const char* greeting = "WELCOME!";
    int text_width1=MeasureText(greeting,100),text_width2=MeasureText("PLEASE SELECT YOUR DIFFICULTY",50);
    
    
    Rectangle easy={320 - MeasureText("EASY MODE", 40)/2,340,img1.width,420},normal={640 - MeasureText("NORMAL MODE", 40)/2,340,img2.width,420},hell={960 - MeasureText("HELL MODE", 40)/2,340,img3.width,420};
    
    //difficulty checker
    while(!IsKeyPressed(KEY_ENTER))
    {
        
        //force quit
        if(WindowShouldClose())
        {
            CloseWindow();
            return 0;
        }
        
        
        //mouse click
        Vector2 mouse=GetMousePosition();
        Vector2 mousedelta=GetMouseDelta();
        if(CheckCollisionPointRec(mouse,easy) && ((mousedelta.x != 0) || (mousedelta.y != 0)))
        {
            t1={(float)315 - MeasureText("EASY MODE", 40)/2,360},t2={(float)310 - MeasureText("EASY MODE", 40)/2,340},t3={(float)310 - MeasureText("EASY MODE", 40)/2,380};
            
            
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                pain=1;
                break;
            }
        }
        else if(CheckCollisionPointRec(mouse,easy) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            pain=1;
            break;
        }
        
        if(CheckCollisionPointRec(mouse,normal) && (mousedelta.x != 0 || mousedelta.y != 0))
        {
            
            t1={(float)635 - MeasureText("NORMAL MODE", 40)/2,360},t2={(float)630 - MeasureText("NORMAL MODE", 40)/2,340},t3={(float)630 - MeasureText("NORMAL MODE", 40)/2,380};
            
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                pain=2;
                break;
            }
        }
        else if(CheckCollisionPointRec(mouse,normal) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            pain=2;
            break;
        }
        
        if(CheckCollisionPointRec(mouse,hell) && (mousedelta.x != 0 || mousedelta.y != 0))
        {
            
            t1={(float)955 - MeasureText("HELL MODE", 40)/2,360},t2={(float)950 - MeasureText("HELL MODE", 40)/2,340},t3={(float)950 - MeasureText("HELL MODE", 40)/2,380};
            
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                pain=3;
                break;
            }
        }
        else if(CheckCollisionPointRec(mouse,hell) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            pain=3;
            break;
        }
        
        //keyboard controll
        if(IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT))
        {
            if(pain==1)
            {
                t1={(float)955 - MeasureText("HELL MODE", 40)/2,360},t2={(float)950 - MeasureText("HELL MODE", 40)/2,340},t3={(float)950 - MeasureText("HELL MODE", 40)/2,380};
                pain=3;
            }
            else if(pain==3)
            {
                t1={(float)635 - MeasureText("NORMAL MODE", 40)/2,360},t2={(float)630 - MeasureText("NORMAL MODE", 40)/2,340},t3={(float)630 - MeasureText("NORMAL MODE", 40)/2,380};
                pain=2;
            }
            else if(pain==2)
            {
                t1={(float)315 - MeasureText("EASY MODE", 40)/2,360},t2={(float)310 - MeasureText("EASY MODE", 40)/2,340},t3={(float)310 - MeasureText("EASY MODE", 40)/2,380};
                pain=1;
            }
        }
        else if(IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT))
        {
            if(pain==1)
            {
                t1={(float)635 - MeasureText("NORMAL MODE", 40)/2,360},t2={(float)630 - MeasureText("NORMAL MODE", 40)/2,340},t3={(float)630 - MeasureText("NORMAL MODE", 40)/2,380};
                pain=2;
            }
            else if(pain==3)
            {
                t1={(float)315 - MeasureText("EASY MODE", 40)/2,360},t2={(float)310 - MeasureText("EASY MODE", 40)/2,340},t3={(float)310 - MeasureText("EASY MODE", 40)/2,380};
                pain=1;
            }
            else if(pain==2)
            {
                t1={(float)955 - MeasureText("HELL MODE", 40)/2,360},t2={(float)950 - MeasureText("HELL MODE", 40)/2,340},t3={(float)950 - MeasureText("HELL MODE", 40)/2,380};
                pain=3;
            }
        }
        
        
        
        
        BeginDrawing();
        ClearBackground(cyan);
        DrawText((const char*)greeting,screen_width/2-text_width1/2,10,100,WHITE);
        DrawText("PLEASE SELECT YOUR DIFFICULTY",screen_width/2-text_width2/2,120,50,WHITE);
        //difficulties
        DrawText("EASY MODE", 320 - MeasureText("EASY MODE", 40)/2, 340, 40, WHITE);
        DrawTexture(img1, 320 - img1.width/2, 380, WHITE);
        
        DrawText("NORMAL MODE", 640 - MeasureText("NORMAL MODE", 40)/2, 340, 40, WHITE);
        DrawTexture(img2, 640 - img2.width/2, 380, WHITE);
        
        DrawText("HELL MODE", 960 - MeasureText("HELL MODE", 40)/2, 340, 40, WHITE);
        DrawTexture(img3, 960 - img3.width/2, 380, WHITE);
        //triangles
        DrawTriangle(t1,t2,t3,YELLOW);
        
        
        EndDrawing();
    }
    
    
    //speed
    if(pain==1)
    {
        
        ball.speedx=((GetRandomValue(0, 1) == 0) ? 1 : -1)*3;
        ball.speedy=((GetRandomValue(0, 1) == 0) ? 1 : -1)*3;
    }
    else if(pain==2)
    {
        ball.speedx=((GetRandomValue(0, 1) == 0) ? 1 : -1)*5;
        ball.speedy=((GetRandomValue(0, 1) == 0) ? 1 : -1)*5;
    }else if(pain==3){
        ball.speedx=((GetRandomValue(0, 1) == 0) ? 1 : -1)*8;
        ball.speedy=((GetRandomValue(0, 1) == 0) ? 1 : -1)*8;
    }
    
    Ball backup=ball;
    int player=1;
    int key=0;
    t1={(float)screen_width/4-MeasureText("1.One player",40)-5,140},t2={(float)screen_width/4-MeasureText("1.One player",40)-15,130},t3={(float)screen_width/4-MeasureText("1.One player",40)-15,150};
    Rectangle a={screen_width/4-MeasureText("1.One player",40)-15,130,300,40},b={screen_width/4-MeasureText("1.One player",40)-15,180,300,40};
    
    //player checker
    while (!key)
    {
        //force quit
        if(WindowShouldClose())
        {
            CloseWindow();
            return 0;
        }
        
        //mouse
        Vector2 mouse=GetMousePosition(),mousedelta=GetMouseDelta();
        if(CheckCollisionPointRec(mouse,a) && ((mousedelta.x != 0) || (mousedelta.y != 0)))
        {
            t1={(float)screen_width/4-MeasureText("1.One player",40)-5,140},t2={(float)screen_width/4-MeasureText("1.One player",40)-15,130},t3={(float)screen_width/4-MeasureText("1.One player",40)-15,150};
            
            
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                player=1;
                break;
            }
        }
        else if(CheckCollisionPointRec(mouse,a) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            player=1;
            break;
        }
        
        if(CheckCollisionPointRec(mouse,b) && ((mousedelta.x != 0) || (mousedelta.y != 0)))
        {
            t1={(float)screen_width/4-MeasureText("1.One player",40)-5,200},t2={(float)screen_width/4-MeasureText("1.One player",40)-15,190},t3={(float)screen_width/4-MeasureText("1.One player",40)-15,210};
            
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                player=2;
                break;
            }
        }
        else if(CheckCollisionPointRec(mouse,b) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            player=2;
            break;
        }
        
        //keyboard controll
        if(IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN))
        {
            if(player==1)
            {
                t1={(float)screen_width/4-MeasureText("1.One player",40)-5,200},t2={(float)screen_width/4-MeasureText("1.One player",40)-15,190},t3={(float)screen_width/4-MeasureText("1.One player",40)-15,210};
                player=2;
            }
            else if(player==2)
            {
                t1={(float)screen_width/4-MeasureText("1.One player",40)-5,140},t2={(float)screen_width/4-MeasureText("1.One player",40)-15,130},t3={(float)screen_width/4-MeasureText("1.One player",40)-15,150};
                player=1;
            }
            
        }
        
        
        
        //drawing
        
        BeginDrawing();
        ClearBackground(cyan);
        DrawTriangle(t1,t2,t3,YELLOW);    
        DrawText("Select the No. of player's:-",screen_width/2-MeasureText("Select the No.of player's:-",80),10,80,WHITE);
        DrawText("1.One player",screen_width/4-MeasureText("1.One player",40),120,40,WHITE);
        DrawText("2.Two player",screen_width/4-MeasureText("1.One player",40),180,40,WHITE);
        DrawTexture(img4,screen_width/2-img4.width/2,270, WHITE);
        
        EndDrawing();
        
        //next
        if(IsKeyPressed(KEY_ENTER))
        key=1;
    }   
    
    
    ToggleFullscreen();
    key=0;
    
    //window before game
    while(!key)
    {
        
        //force quit
        if(WindowShouldClose())
        {
            CloseWindow();
            return 0;
        }
        
        
        BeginDrawing();
        ClearBackground(cyan);
        DrawLine(screen_width/2,0,screen_width/2,screen_height,BLACK);
        DrawText("Press Esc to quit at any time.",screen_width/2-MeasureText("Press Esc to quit at any time.",70)/2,280-35,70,WHITE);
        DrawText("Press any key to continue.",screen_width/2 - MeasureText("Press any key to continue.",50)/2,360+35+10,50,WHITE);
        box1.draw();
        box2.draw();
        ball.draw();
        
        EndDrawing();
        
        if(GetKeyPressed() != 0)
        {
            key=1;
            SetMousePosition(screen_width,screen_height);
        }
        
    }
    
    if(player==1)
    {
        //against cpu
        while(!WindowShouldClose())
        {
            //controlls
            // if(IsKeyDown(KEY_W))
            // box1.y-=5;
            // if(IsKeyDown(KEY_S))
            // box1.y+=5;
            if(pain==1)
            {
                if(ball.y<(box1.y+box1.height/2))
                box1.y-=5;
                if(ball.y>(box1.y+box1.height/2))
                box1.y+=5;
            }
            else if (pain==2)
            {
                if(ball.y<(box1.y+box1.height/2))
                box1.y-=6;
                if(ball.y>(box1.y+box1.height/2))
                box1.y+=6;
            }
            else if (pain==3)
            {
                if(ball.y<(box1.y+box1.height/2))
                box1.y-=8;
                if(ball.y>(box1.y+box1.height/2))
                box1.y+=8;
            }
            if(box1.y<=0)
            box1.y+=5;
            if(box1.y+box1.height>=screen_height)
            box1.y-=5;
            if(IsKeyDown(KEY_UP))
            box2.y-=5;
            if(IsKeyDown(KEY_DOWN))
            box2.y+=5;
            if(box2.y<=0)
            box2.y+=5;
            if(box2.y+box2.height>=screen_height)
            box2.y-=5;
            
            
            
            //update 
            ball.update();
            //collision
            if(CheckCollisionCircleRec(Vector2{ball.x,ball.y},ball.radius,Rectangle{box1.x,box1.y,box1.width,box1.height}))
            ball.speedx*=-1;
            if(CheckCollisionCircleRec(Vector2{ball.x,ball.y},ball.radius,Rectangle{box2.x,box2.y,box2.width,box2.height}))
            ball.speedx*=-1;
            //ball loop
            if(ball.x>screen_width)
            {
                box1.score++;
                
                while (GetKeyPressed()==0)
                {
                    
                    
                    
                    BeginDrawing();
                    ClearBackground(cyan);
                    DrawText("Up arrow",screen_width-MeasureText("Up arrow",20)-40,10,20,WHITE);
                    DrawText("Down arrow",screen_width-MeasureText("Down arrow",20)-40,screen_height-30,20,WHITE);
                    DrawText(TextFormat("%d",box1.score),screen_width/4-MeasureText(TextFormat("%d",box1.score),70),50,70,WHITE);
                    DrawText(TextFormat("%d",box2.score),3*screen_width/4-MeasureText(TextFormat("%d",box2.score),70),50,70,WHITE);
                    DrawLine(screen_width/2,0,screen_width/2,screen_height,BLACK);
                    DrawText("Move to continue",screen_width/2-MeasureText("Move to continue",50)/2,20,50,WHITE);
                    box1.draw();
                    box2.draw();
                    no_velocity_center.draw();
                    EndDrawing();
                    
                    if(WindowShouldClose())
                    {
                        CloseWindow();
                        return 0;
                    }
                }
                
                
                
                ball=backup;
                if(pain==1)
                {
                    
                    ball.speedx=((GetRandomValue(0, 1) == 0) ? 1 : -1)*3;
                    ball.speedy=((GetRandomValue(0, 1) == 0) ? 1 : -1)*3;
                }
                else if(pain==2)
                {
                    ball.speedx=((GetRandomValue(0, 1) == 0) ? 1 : -1)*5;
                    ball.speedy=((GetRandomValue(0, 1) == 0) ? 1 : -1)*5;
                }else if(pain==3){
                    ball.speedx=((GetRandomValue(0, 1) == 0) ? 1 : -1)*7;
                    ball.speedy=((GetRandomValue(0, 1) == 0) ? 1 : -1)*7;
                }
            }
            if(ball.x<0)
            {
                box2.score++;
                while (GetKeyPressed()==0)
                {
                    
                    
                    BeginDrawing();
                    ClearBackground(cyan);
                    DrawText("Up arrow",screen_width-MeasureText("Up arrow",20)-40,10,20,WHITE);
                    DrawText("Down arrow",screen_width-MeasureText("Down arrow",20)-40,screen_height-30,20,WHITE);
                    DrawText(TextFormat("%d",box1.score),screen_width/4-MeasureText(TextFormat("%d",box1.score),70),50,70,WHITE);
                    DrawText(TextFormat("%d",box2.score),3*screen_width/4-MeasureText(TextFormat("%d",box2.score),70),50,70,WHITE);
                    DrawLine(screen_width/2,0,screen_width/2,screen_height,BLACK);
                    DrawText("Move to continue",screen_width/2-MeasureText("Move to continue",50)/2,20,50,WHITE);
                    box1.draw();
                    box2.draw();
                    no_velocity_center.draw();
                    EndDrawing();
                    
                    if(WindowShouldClose())
                    {
                        CloseWindow();
                        return 0;
                    }
                }       
                
                ball=backup;
                
                if(pain==1)
                {
                    
                    ball.speedx=((GetRandomValue(0, 1) == 0) ? 1 : -1)*3;
                    ball.speedy=((GetRandomValue(0, 1) == 0) ? 1 : -1)*3;
                }
                else if(pain==2)
                {
                    ball.speedx=((GetRandomValue(0, 1) == 0) ? 1 : -1)*5;
                    ball.speedy=((GetRandomValue(0, 1) == 0) ? 1 : -1)*5;
                }else if(pain==3){
                    ball.speedx=((GetRandomValue(0, 1) == 0) ? 1 : -1)*7;
                    ball.speedy=((GetRandomValue(0, 1) == 0) ? 1 : -1)*7;
                }
                
            }
            
            //ending
            
            if(box1.score==10)
            {
                while(1)
                {
                    
                    
                    BeginDrawing();
                    ClearBackground(cyan);
                    DrawText("Up arrow",screen_width-MeasureText("Up arrow",20)-40,10,20,WHITE);
                    DrawText("Down arrow",screen_width-MeasureText("Down arrow",20)-40,screen_height-30,20,WHITE);
                    DrawText(TextFormat("%d",box1.score),screen_width/4-MeasureText(TextFormat("%d",box1.score),70),50,70,WHITE);
                    DrawText(TextFormat("%d",box2.score),3*screen_width/4-MeasureText(TextFormat("%d",box2.score),70),50,70,WHITE);
                    DrawLine(screen_width/2,0,screen_width/2,screen_height,BLACK);
                    DrawText("CPU WINS!!!",screen_width/2-MeasureText("CPU WINS!!!",70)/2,20,70,WHITE);
                    DrawText("Press Esc to quit.",screen_width/2-MeasureText("Press Esc to quit.",40)/2,280-35,40,WHITE);
                    DrawText("-made by aaditya aka Aariso0",screen_width-MeasureText("-made by aaditya aka Aariso0",30)-30,screen_height-60,30,WHITE);
                    box1.draw();
                    box2.draw();
                    ball.draw();
                    EndDrawing();
                    
                    if(WindowShouldClose())
                    {
                        CloseWindow();
                        return 0;
                    }
                    
                }
            }
            else if(box2.score==10)
            {
                while(1)
                {
                    
                    
                    BeginDrawing();
                    ClearBackground(cyan);
                    DrawText("Up arrow",screen_width-MeasureText("Up arrow",20)-40,10,20,WHITE);
                    DrawText("Down arrow",screen_width-MeasureText("Down arrow",20)-40,screen_height-30,20,WHITE);
                    DrawText(TextFormat("%d",box1.score),screen_width/4-MeasureText(TextFormat("%d",box1.score),70),50,70,WHITE);
                    DrawText(TextFormat("%d",box2.score),3*screen_width/4-MeasureText(TextFormat("%d",box2.score),70),50,70,WHITE);
                    DrawLine(screen_width/2,0,screen_width/2,screen_height,BLACK);
                    DrawText("PLAYER WINS!!!",screen_width/2-MeasureText("PLAYER WINS!!!",70)/2,20,70,WHITE);
                    DrawText("Press Esc to quit.",screen_width/2-MeasureText("Press Esc to quit.",40)/2,280-35,40,WHITE);
                    DrawText("-made by aaditya aka Aariso0",screen_width-MeasureText("-made by aaditya aka Aariso0",30)-30,screen_height-60,30,WHITE);
                    box1.draw();
                    box2.draw();
                    ball.draw();
                    EndDrawing();
                    
                    if(WindowShouldClose())
                    {
                        CloseWindow();
                        return 0;
                    }
                }
            }
            
            
            //drawing
            
            BeginDrawing();
            ClearBackground(cyan);
            DrawText("Up arrow",screen_width-MeasureText("Up arrow",20)-40,10,20,WHITE);
            DrawText("Down arrow",screen_width-MeasureText("Down arrow",20)-40,screen_height-30,20,WHITE);
            DrawText(TextFormat("%d",box1.score),screen_width/4-MeasureText(TextFormat("%d",box1.score),70),50,70,WHITE);
            DrawText(TextFormat("%d",box2.score),3*screen_width/4-MeasureText(TextFormat("%d",box2.score),70),50,70,WHITE);
            DrawLine(screen_width/2,0,screen_width/2,screen_height,BLACK);
            box1.draw();
            box2.draw();
            ball.draw();
            EndDrawing();
        }
        
    }
    else if(player==2)
    {
        //against another player
        while(!WindowShouldClose())
        {
            //controlls
            if(IsKeyDown(KEY_W))
            box1.y-=5;
            if(IsKeyDown(KEY_S))
            box1.y+=5;
            if(box1.y<=0)
            box1.y+=5;
            if(box1.y+box1.height>=screen_height)
            box1.y-=5;
            if(IsKeyDown(KEY_UP))
            box2.y-=5;
            if(IsKeyDown(KEY_DOWN))
            box2.y+=5;
            if(box2.y<=0)
            box2.y+=5;
            if(box2.y+box2.height>=screen_height)
            box2.y-=5;
            
            
            
            //update 
            ball.update();
            //collision
            if(CheckCollisionCircleRec(Vector2{ball.x,ball.y},ball.radius,Rectangle{box1.x,box1.y,box1.width,box1.height}))
            ball.speedx*=-1;
            if(CheckCollisionCircleRec(Vector2{ball.x,ball.y},ball.radius,Rectangle{box2.x,box2.y,box2.width,box2.height}))
            ball.speedx*=-1;
            //ball loop
            if(ball.x>screen_width)
            {
                box1.score++;
                
                while (GetKeyPressed()==0)
                {
                    
                    
                    
                    BeginDrawing();
                    ClearBackground(cyan);
                    DrawText("Up arrow",screen_width-MeasureText("Up arrow",20)-40,10,20,WHITE);
                    DrawText("Down arrow",screen_width-MeasureText("Down arrow",20)-40,screen_height-30,20,WHITE);
                    DrawText("W",MeasureText("W",20)+20,10,20,WHITE);
                    DrawText("S",MeasureText("S",20)+20,screen_height-30,20,WHITE);
                    DrawText(TextFormat("%d",box1.score),screen_width/4-MeasureText(TextFormat("%d",box1.score),70),50,70,WHITE);
                    DrawText(TextFormat("%d",box2.score),3*screen_width/4-MeasureText(TextFormat("%d",box2.score),70),50,70,WHITE);
                    DrawLine(screen_width/2,0,screen_width/2,screen_height,BLACK);
                    DrawText("Move to continue",screen_width/2-MeasureText("Move to continue",50)/2,20,50,WHITE);
                    box1.draw();
                    box2.draw();
                    no_velocity_center.draw();
                    EndDrawing();
                    
                    if(WindowShouldClose())
                    {
                        CloseWindow();
                        return 0;
                    }
                }
                
                
                
                ball=backup;
                if(pain==1)
                {
                    
                    ball.speedx=((GetRandomValue(0, 1) == 0) ? 1 : -1)*3;
                    ball.speedy=((GetRandomValue(0, 1) == 0) ? 1 : -1)*3;
                }
                else if(pain==2)
                {
                    ball.speedx=((GetRandomValue(0, 1) == 0) ? 1 : -1)*5;
                    ball.speedy=((GetRandomValue(0, 1) == 0) ? 1 : -1)*5;
                }else if(pain==3){
                    ball.speedx=((GetRandomValue(0, 1) == 0) ? 1 : -1)*7;
                    ball.speedy=((GetRandomValue(0, 1) == 0) ? 1 : -1)*7;
                }
            }
            if(ball.x<0)
            {
                box2.score++;
                while (GetKeyPressed()==0)
                {
                    
                    
                    BeginDrawing();
                    ClearBackground(cyan);
                    DrawText("Up arrow",screen_width-MeasureText("Up arrow",20)-40,10,20,WHITE);
                    DrawText("Down arrow",screen_width-MeasureText("Down arrow",20)-40,screen_height-30,20,WHITE);
                    DrawText("W",MeasureText("W",20)+20,10,20,WHITE);
                    DrawText("S",MeasureText("S",20)+20,screen_height-30,20,WHITE);
                    DrawText(TextFormat("%d",box1.score),screen_width/4-MeasureText(TextFormat("%d",box1.score),70),50,70,WHITE);
                    DrawText(TextFormat("%d",box2.score),3*screen_width/4-MeasureText(TextFormat("%d",box2.score),70),50,70,WHITE);
                    DrawLine(screen_width/2,0,screen_width/2,screen_height,BLACK);
                    DrawText("Move to continue",screen_width/2-MeasureText("Move to continue",50)/2,20,50,WHITE);
                    box1.draw();
                    box2.draw();
                    no_velocity_center.draw();
                    EndDrawing();
                    
                    if(WindowShouldClose())
                    {
                        CloseWindow();
                        return 0;
                    }
                }       
                
                ball=backup;
                
                if(pain==1)
                {
                    
                    ball.speedx=((GetRandomValue(0, 1) == 0) ? 1 : -1)*3;
                    ball.speedy=((GetRandomValue(0, 1) == 0) ? 1 : -1)*3;
                }
                else if(pain==2)
                {
                    ball.speedx=((GetRandomValue(0, 1) == 0) ? 1 : -1)*5;
                    ball.speedy=((GetRandomValue(0, 1) == 0) ? 1 : -1)*5;
                }else if(pain==3){
                    ball.speedx=((GetRandomValue(0, 1) == 0) ? 1 : -1)*7;
                    ball.speedy=((GetRandomValue(0, 1) == 0) ? 1 : -1)*7;
                }
                
            }
            
            //ending
            
            if(box1.score==10)
            {
                while(1)
                {
                    
                    
                    BeginDrawing();
                    ClearBackground(cyan);
                    DrawText("Up arrow",screen_width-MeasureText("Up arrow",20)-40,10,20,WHITE);
                    DrawText("Down arrow",screen_width-MeasureText("Down arrow",20)-40,screen_height-30,20,WHITE);
                    DrawText("W",MeasureText("W",20)+20,10,20,WHITE);
                    DrawText("S",MeasureText("S",20)+20,screen_height-30,20,WHITE);
                    DrawText(TextFormat("%d",box1.score),screen_width/4-MeasureText(TextFormat("%d",box1.score),70),50,70,WHITE);
                    DrawText(TextFormat("%d",box2.score),3*screen_width/4-MeasureText(TextFormat("%d",box2.score),70),50,70,WHITE);
                    DrawLine(screen_width/2,0,screen_width/2,screen_height,BLACK);
                    DrawText("PLAYER 1 WINS!!!",screen_width/2-MeasureText("PLAYER 1 WINS!!!",70)/2,20,70,WHITE);
                    DrawText("Press Esc to quit.",screen_width/2-MeasureText("Press Esc to quit.",40)/2,280-35,40,WHITE);
                    DrawText("-made by aaditya aka Aariso0",screen_width-MeasureText("-made by aaditya aka Aariso0",30)-30,screen_height-60,30,WHITE);
                    box1.draw();
                    box2.draw();
                    ball.draw();
                    EndDrawing();
                    
                    if(WindowShouldClose())
                    {
                        CloseWindow();
                        return 0;
                    }
                }
            }
            else if(box2.score==10)
            {
                while(1)
                {
                    
                    
                    BeginDrawing();
                    ClearBackground(cyan);
                    DrawText("Up arrow",screen_width-MeasureText("Up arrow",20)-40,10,20,WHITE);
                    DrawText("Down arrow",screen_width-MeasureText("Down arrow",20)-40,screen_height-30,20,WHITE);
                    DrawText("W",MeasureText("W",20)+20,10,20,WHITE);
                    DrawText("S",MeasureText("S",20)+20,screen_height-30,20,WHITE);
                    DrawText(TextFormat("%d",box1.score),screen_width/4-MeasureText(TextFormat("%d",box1.score),70),50,70,WHITE);
                    DrawText(TextFormat("%d",box2.score),3*screen_width/4-MeasureText(TextFormat("%d",box2.score),70),50,70,WHITE);
                    DrawLine(screen_width/2,0,screen_width/2,screen_height,BLACK);
                    DrawText("PLAYER 2 WINS!!!",screen_width/2-MeasureText("PLAYER 2 WINS!!!",70)/2,20,70,WHITE);
                    DrawText("Press Esc to quit.",screen_width/2-MeasureText("Press Esc to quit.",40)/2,280-35,40,WHITE);
                    DrawText("-made by aaditya aka Aariso0",screen_width-MeasureText("-made by aaditya aka Aariso0",30)-30,screen_height-60,30,WHITE);
                    box1.draw();
                    box2.draw();
                    ball.draw();
                    EndDrawing();
                    
                    if(WindowShouldClose())
                    {
                        CloseWindow();
                        return 0;
                    }
                }
            }
            
            
            //drawing
            
            BeginDrawing();
            ClearBackground(cyan);
            DrawText("Up arrow",screen_width-MeasureText("Up arrow",20)-40,10,20,WHITE);
            DrawText("Down arrow",screen_width-MeasureText("Down arrow",20)-40,screen_height-30,20,WHITE);
            DrawText("W",MeasureText("W",20)+20,10,20,WHITE);
            DrawText("S",MeasureText("S",20)+20,screen_height-30,20,WHITE);
            DrawText(TextFormat("%d",box1.score),screen_width/4-MeasureText(TextFormat("%d",box1.score),70),50,70,WHITE);
            DrawText(TextFormat("%d",box2.score),3*screen_width/4-MeasureText(TextFormat("%d",box2.score),70),50,70,WHITE);
            DrawLine(screen_width/2,0,screen_width/2,screen_height,BLACK);
            box1.draw();
            box2.draw();
            ball.draw();
            EndDrawing();
        }
        
    }
    
    CloseWindow();
    return 0;
}
