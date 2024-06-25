/*
    EnableWorldTime();
    DisableWorldTime();
*/

#if !defined delay_world_time
    #define delay_world_time (0)
#endif

enum e_world_timer
{
    timer
};
new w_times[e_world_timer];



/*
        .oooooo..o ooooooooooooo   .oooooo.     .oooooo.   oooo    oooo  .oooooo..o 
        d8P'    `Y8 8'   888   `8  d8P'  `Y8b   d8P'  `Y8b  `888   .8P'  d8P'    `Y8 
        Y88bo.           888      888      888 888           888  d8'    Y88bo.      
        `"Y8888o.       888      888      888 888           88888[       `"Y8888o.  
            `"Y88b      888      888      888 888           888`88b.         `"Y88b 
        oo     .d8P      888      `88b    d88' `88b    ooo   888  `88b.  oo     .d8P 
        8""88888P'      o888o      `Y8bood8P'   `Y8bood8P'  o888o  o888o 8""88888P'  
*/

stock EnableWorldTime()
{
    @world_time();
    w_times[timer] = SetTimer("@world_time", (1000 * 60), true);
}

stock DisableWorldTime(hour = 12)
{
    KillTimer(w_times[timer]);
    SetWorldTime(hour);
}



/*
        ooooooooo.   ooooo     ooo oooooooooo.  ooooo        ooooo   .oooooo.   
        `888   `Y88. `888'     `8' `888'   `Y8b `888'        `888'  d8P'  `Y8b  
        888   .d88'  888       8   888     888  888          888  888          
        888ooo88P'   888       8   888oooo888'  888          888  888          
        888          888       8   888    `88b  888          888  888          
        888          `88.    .8'   888    .88P  888       o  888  `88b    ooo  
        o888o           `YbodP'    o888bood8P'  o888ooooood8 o888o  `Y8bood8P'                         
*/

public OnGameModeInit()
{
    #if defined inc_world_time
        return inc_world_time();
    #else
        return 1;
    #endif
}

#if defined _ALS_OnGameModeInit
    #undef OnGameModeInit
#else
    #define _ALS_OnGameModeInit
#endif

#define OnGameModeInit inc_world_time
#if defined inc_world_time
    forward inc_world_time();
#endif




/*
        ooooooooooooo ooooo ooo        ooooo oooooooooooo ooooooooo.    .oooooo..o 
        8'   888   `8 `888' `88.       .888' `888'     `8 `888   `Y88. d8P'    `Y8 
            888       888   888b     d'888   888          888   .d88' Y88bo.      
            888       888   8 Y88. .P  888   888oooo8     888ooo88P'   `"Y8888o.  
            888       888   8  `888'   888   888    "     888`88b.         `"Y88b 
            888       888   8    Y     888   888       o  888  `88b.  oo     .d8P 
            o888o     o888o o8o        o888o o888ooooood8 o888o  o888o 8""88888P'
*/

forward @world_time();
public @world_time()
{
    new hour;
    gettime(hour);

    SetWorldTime((hour - delay_world_time));
}
