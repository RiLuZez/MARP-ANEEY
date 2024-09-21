#include <YSI\y_hooks>
#include <a_http>

#define Function_IP:%1(%2) forward %1(%2); public %1(%2)

forward DataReceived(playerid,success_type);

enum ip_a //player ip
{
	host_name[60],
	i_provider[80],
	country[60],
	region[45],
	i_type,
	i_gmt,
	bool:fail_a,
	index_data,
	Float:latitude,
	Float:longitude,
};

new	IPlayerInfo[MAX_PLAYERS][ip_a]; //player ip

enum ip_b //only ip
{
	host_name_2[60],
	i_provider_2[80],
	country_2[60],
	region_2[45],
	i_type_2,
	i_gmt_2,
	bool:fail_a_2,
	ip_check[16],
	Float:latitude_2,
	Float:longitude_2,
};

new	IPLocData[ip_b]; //only ip

#define GetHost(%1) IPlayerInfo[%1][host_name]
#define GetISP(%1) IPlayerInfo[%1][i_provider]
#define GetCountry(%1) IPlayerInfo[%1][country]
#define GetGMT(%1) IPlayerInfo[%1][i_gmt]
#define GetRegion(%1) IPlayerInfo[%1][region]
#define GetProxy(%1) IPlayerInfo[%1][i_type]
#define GetLatitude(%1) IPlayerInfo[%1][latitude]
#define GetLongitude(%1) IPlayerInfo[%1][longitude]

#define CHECK_NOTFOR_PLAYER -1
#define CHECK_SUCCESS 0

Function_IP:GetIPlayerInfo(s_ip[]) //only ip
{
    new string[60];
    format(IPLocData[ip_check],16,s_ip);
	format(string, sizeof(string), "iPlayerInfo.ultra-h.com/iPlayerInfo/api.php?ip=%s",s_ip);
	HTTP(-1, HTTP_GET, string, "", "DataResponse");
}

Function_IP:GetPlayerIPlayerInfo(playerid) //player ip
{
    if(!IsPlayerNPC(playerid))
    {
	    new string[60];
	    new s_ip[16];
	    GetPlayerIp(playerid, s_ip, 16);
		format(string, sizeof(string), "iPlayerInfo.ultra-h.com/iPlayerInfo/api.php?ip=%s",s_ip);
		HTTP(playerid, HTTP_GET, string, "", "DataResponse");
	}
	return 1;
}

Function_IP:DataResponse(index, response_code, data[])
{
	if(index >= 0)
	{
		new playerid = index;
		if(response_code != 200)
		{
		    if(!IPlayerInfo[playerid][fail_a])
			{
			    IPlayerInfo[playerid][fail_a] = true;
				GetPlayerIPlayerInfo(playerid);
			}
		    else
		    {
		        CopyStringEx(IPlayerInfo[playerid][host_name],"Unknown", 60);
			    CopyStringEx(IPlayerInfo[playerid][country],"Unknown", 60);
			    CopyStringEx(IPlayerInfo[playerid][region],"Unknown", 45);
			    CopyStringEx(IPlayerInfo[playerid][i_provider],"Unknown", 80);
				IPlayerInfo[playerid][i_gmt] = 0;
			    IPlayerInfo[playerid][i_type] = 0;
			    IPlayerInfo[playerid][latitude] = 0;
			    IPlayerInfo[playerid][longitude] = 0;
		        IPlayerInfo[playerid][fail_a] = false;
		        if(funcidx("DataReceived")) CallLocalFunction("DataReceived", "id", playerid,1);
		    }
		}
		else
		{
		    sscanf(data, "p<|>s[60]s[80]s[60]s[45]ddff",
		    IPlayerInfo[playerid][host_name],
			IPlayerInfo[playerid][i_provider],
			IPlayerInfo[playerid][country],
			IPlayerInfo[playerid][region],
			IPlayerInfo[playerid][i_gmt],
			IPlayerInfo[playerid][i_type],
			IPlayerInfo[playerid][latitude],
   			IPlayerInfo[playerid][longitude]);
			if(IPlayerInfo[playerid][fail_a]) IPlayerInfo[playerid][fail_a] = false;
			if(funcidx("DataReceived")) CallLocalFunction("DataReceived", "id", playerid,0);
		}
	}
	else
	{
	    if(response_code != 200)
		{
		    if(!IPLocData[fail_a_2])
			{
			    IPLocData[fail_a_2] = true;
				GetIPlayerInfo(IPLocData[ip_check]);
			}
		    else
		    {
		        CopyStringEx(IPLocData[host_name_2],"Unknown", 60);
		        CopyStringEx(IPLocData[i_provider_2],"Unknown", 60);
		        CopyStringEx(IPLocData[country_2],"Unknown", 45);
		        CopyStringEx(IPLocData[region_2],"Unknown", 80);
				IPLocData[i_gmt_2] = 0;
		        IPLocData[i_type_2] = 0;
		        IPLocData[latitude_2] = 0;
		        IPLocData[longitude_2] = 0;
		        IPLocData[fail_a_2] = false;
		        if(funcidx("DataReceived")) CallLocalFunction("DataReceived", "id", -1,1);
		    }
		}
		else
		{
		    sscanf(data, "p<|>s[60]s[80]s[60]s[45]ddff",
		    IPLocData[host_name_2],
			IPLocData[i_provider_2],
			IPLocData[country_2],
			IPLocData[region_2],
			IPLocData[i_gmt_2],
			IPLocData[i_type_2],
			IPLocData[latitude_2],
			IPLocData[longitude_2]);
		    if(funcidx("DataReceived")) CallLocalFunction("DataReceived", "id", -1,0);
		    
		}
	}
}

hook OnPlayerConnect(playerid)
{
    CopyStringEx(IPlayerInfo[playerid][host_name],"NONE", 60);
    CopyStringEx(IPlayerInfo[playerid][country],"NONE", 60);
    CopyStringEx(IPlayerInfo[playerid][region],"NONE", 45);
    CopyStringEx(IPlayerInfo[playerid][i_provider],"NONE", 80);
	IPlayerInfo[playerid][i_gmt] = 0;
    IPlayerInfo[playerid][i_type] = 0;
    IPlayerInfo[playerid][latitude] = 0;
    IPlayerInfo[playerid][longitude] = 0;
    IPlayerInfo[playerid][fail_a] = false;
	return 1;
}

stock CopyStringEx(dest[], const source[], maxlength=sizeof dest)
{
	strcat((dest[0] = EOS, dest), source, maxlength);
}


