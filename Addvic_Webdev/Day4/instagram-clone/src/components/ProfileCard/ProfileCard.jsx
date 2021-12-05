import React from "react";
import "./ProfileCard.css";

export default function ProfileCard({
  mainProfile,
  userName,
  name,
  btnText,
  height,
  width,
}) {
  return (
    <div className="profileCard">
      <img src={mainProfile} alt="profile pic" height={height} width={width} />
      <div className="profileCard__Names">
        <span id="profileCard__Username">{userName}</span>
        <span id="profileCard__Name">{name}</span>
      </div>
      <a href="#">
        <small>{btnText}</small>
      </a>
    </div>
  );
}
