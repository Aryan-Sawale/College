import React from "react";
import ProfileCard from "../ProfileCard/ProfileCard";
import "./Sidebar.css";

import mainProfile from "../../assets/profiles/profile5.jpg";
import mainProfile1 from "../../assets/profiles/profile1.jpg";
import mainProfile2 from "../../assets/profiles/profile2.jpg";
import mainProfile3 from "../../assets/profiles/profile3.jpg";
import mainProfile4 from "../../assets/profiles/profile4.jpg";

export default function Sidebar() {
  return (
    <div className="sidebar">
      <ProfileCard
        mainProfile={mainProfile}
        userName="aryan_sawale"
        name="Aryan Sawale"
        btnText="Switch"
        height="68px"
        width="68px"
      />

      <div className="suggestionArea">
        <span>Suggestions for you</span>
        <a href="#">
          <small>See All</small>
        </a>
      </div>

      <div className="suggestionCards">
        <ProfileCard
          mainProfile={mainProfile1}
          userName="vivekbarhate_007"
          name="Followed by vina.."
          btnText="Follow"
          height="40px"
          width="40px"
        />

        <ProfileCard
          mainProfile={mainProfile2}
          userName="adityapawar20"
          name="Followed by dev..."
          btnText="Follow"
          height="40px"
          width="40px"
        />

        <ProfileCard
          mainProfile={mainProfile3}
          userName="diya_sonavale_43"
          name="Suggested for you"
          btnText="Follow"
          height="40px"
          width="40px"
        />

        <ProfileCard
          mainProfile={mainProfile4}
          userName="ankita_joshi7878"
          name="Followed by omk.."
          btnText="Follow"
          height="40px"
          width="40px"
        />
      </div>

      <div className="sidebarLinks">
        <span>About &#183; </span>
        <span>Help &#183; </span>
        <span>Press &#183; </span>
        <span>API &#183; </span>
        <span>Jobs &#183; </span>
        <span>Privacy &#183; </span>
        <span>Terms &#183; </span>
        <span>Locations &#183; </span>
        <span>Top accounts &#183; </span>
        <span>Hashtags &#183; </span>
        <span>Language &#183; </span>
        <br />
        <br />
        <span>© 2021 INSTAGRAM FROM META</span>
      </div>
    </div>
  );
}
