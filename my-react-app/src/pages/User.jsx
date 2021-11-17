import React from "react";
import UserCard from '../components/UserCard';
import profileimg from '../assets/profile.png';

const User = () => {
    return(
        <div>
            <UserCard Name="Nakul" URL="https://picsum.photos/200"/>
            <UserCard Name="Aryan" URL="https://picsum.photos/201"/>
            <UserCard Name="Alok" URL="https://picsum.photos/202"/>
            <UserCard Name="Saee" URL={profileimg}/>
        </div>
    )
}

export default User;