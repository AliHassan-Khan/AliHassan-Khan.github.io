// Content migrated into the devportfolio template by Ryan Fitzgerald (MIT License)
// https://github.com/RyanFitzgerald/devportfolio

interface Project {
  name: string;
  description: string;
  link?: string;
  skills?: string[];
}

interface Experience {
  company: string;
  title: string;
  dateRange: string;
  bullets: string[];
}

interface Education {
  school?: string;
  degree: string;
  dateRange: string;
  achievements: string[];
}

interface SiteConfig {
  name: string;
  title: string;
  tagline?: string;
  degree?: string;
  description: string;
  accentColor: string;
  photo?: string;
  social: {
    email?: string;
    linkedin?: string;
    twitter?: string;
    github?: string;
  };
  aboutMe: string;
  currentlyLearning?: string;
  skills: string[];
  projectsIntro?: string;
  projects: Project[];
  experience: Experience[];
  education: Education[];
}

export const siteConfig: SiteConfig = {
  name: "Muhammad Ali Hassan",
  title: "Information Security Student",
  tagline: "Networking | Linux | Always Learning",
  degree: "BE Information Security · 3rd Semester",
  description:
    "Portfolio of Muhammad Ali Hassan, BE Information Security student interested in security, networking and Linux.",
  accentColor: "#0b7a5c",
  photo: "/photo.jpg",
  social: {
    email: "ali555hassankhan@gmail.com",
    github: "https://github.com/AliHassan-Khan",
  },
  aboutMe:
    "I'm Muhammad Ali Hassan, a third-semester BE Information Security student. I'm drawn to security and networking because I like understanding how systems actually work, and how they can be protected when they break. At the moment I'm building a foundation in Linux, Git and programming in C++ and Java, and I'm applying it through labs in my Applications of ICT course, where I've set up Windows and WSL2 and explored disks, partitions and boot sectors. I enjoy learning new things, and I try to turn what I learn into something I can show, whether that is a lab write-up, a small project or a website like this one. My goal is to grow into a security professional who understands both the technology and the risks around it.",
  currentlyLearning: "Currently learning: networking fundamentals and security basics.",
  skills: [
    "Linux",
    "Git & GitHub",
    "C++",
    "Java",
    "WSL2 & Windows setup",
    "Disk forensics basics",
  ],
  projectsIntro:
    "C++ projects built from my Applications of ICT labs (CS-117).",
  projects: [
    {
      name: "MBR Boot Sector Analyzer",
      description:
        "C++ tool from Lab 04 that reads a disk image, checks the 55 AA signature and decodes the partition table.",
      link: "https://github.com/AliHassan-Khan/AliHassan-Khan.github.io/tree/main/projects/mbr-analyzer",
      skills: ["C++17", "MBR", "Disk images"],
    },
    {
      name: "Disk Layout Planner",
      description:
        "C++ tool from Lab 03 that plans a UEFI/GPT Windows layout (ESP, MSR, C:) and shows the MBR limits.",
      link: "https://github.com/AliHassan-Khan/AliHassan-Khan.github.io/tree/main/projects/disk-layout-planner",
      skills: ["C++17", "UEFI/GPT", "Disk layout"],
    },
    {
      name: "Grade Calculator",
      description:
        "Console program in C++ that turns marks and credit hours into letter grades and a weighted GPA.",
      link: "https://github.com/AliHassan-Khan/AliHassan-Khan.github.io/tree/main/projects/grade-calculator",
      skills: ["C++17", "Console app"],
    },
  ],
  // No work experience yet: leaving this empty hides the section.
  experience: [],
  education: [
    {
      degree: "BE Information Security",
      dateRange: "3rd Semester (current)",
      achievements: [
        "Applications of ICT (CS-117) labs: set up Windows and WSL2, and explored disks, partitions and boot sectors",
        "Built C++ tools from Lab 03 (disk layout planner) and Lab 04 (MBR analyzer)",
        "Building a foundation in Linux, Git, C++ and Java",
      ],
    },
  ],
};
