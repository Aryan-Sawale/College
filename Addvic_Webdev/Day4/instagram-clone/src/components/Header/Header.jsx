import React from "react";
import "./Header.css";
import logo from "../../assets/logo.png";
import searchIcon from "../../assets/gray_search_icon.png";
import { HiHome } from "react-icons/hi";
import { RiMessengerLine } from "react-icons/ri";
import { ImCompass2 } from "react-icons/im";
import { BsHeart } from "react-icons/bs";
import { BiUserCircle } from "react-icons/bi";
import profilePic from "../../assets/profiles/profile5.jpg";

export default function Header() {
  return (
    <div className="header">
      <div className="header__logo">
        <img src={logo} alt="logo" width="103px" height="29px" />
      </div>

      <div className="header__search">
        <img src={searchIcon} alt="search icon" width="15px" />
        <input type="search" placeholder="Search" />
      </div>

      <div className="header__icons">
        <HiHome size="26px" />
        <RiMessengerLine size="26px" />
        <ImCompass2 />
        <BsHeart />
        {/* <BiUserCircle size="26px" /> */}
        <img
          src={profilePic}
          alt="profilePic"
          height="26px"
          width="26px"
          id="dp"
        />
      </div>
    </div>
  );
}
