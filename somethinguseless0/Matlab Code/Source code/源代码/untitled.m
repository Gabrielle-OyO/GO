1.
x=0:.1:8*pi;
y=5*sin(x/2);
plot(x,y);
title('the first figure');
xlabel('横坐标');
ylabel('纵坐标');
legend('y=5*sin(x/2);');
grid on

2.
clc;
clear all;
close all;
x=0:pi/100:2*pi;
y1=0.8*exp(-0.2*x).*sin(2*pi*x);
plot(x, y1,'linestyle','.','linewidth',0.1,'color', 'b')
hold on
y2=2*exp(-0.5 * x).*cos(pi*x);
plot(x, y2,'linestyle','x','linewidth',0.5,'color', 'r');
hold off

3.
clc;
clear all;
close all;
x=0:0.1:2*pi;
subplot(3,1,1);
plot(x,sin(x));
subplot(3,3,[4,7]);
plot(x,sin(2*x));
subplot(3,3,[5,6]);
plot(x,sin(3*x));
subplot(3,3,8);
plot(x,sin(4*x));
subplot(3,3,9);
plot(x,sin(5*x));
4（1）.
[x,y]=meshgrid(-8:0.5:8);
z=sin(sqrt(x.^2+y^2))./sqrt(x.^2+y.^2+eps);
subplot(2,2,1);
mesh(x, y,z);
title('mesh(x, y,z)')
subplot(2,2,2);
meshc(x, y, z);
title('meshc(x, y,z)')
subplot(2,2,3);
meshz(x, y,z)
title('meshz(x, y,z)')
subplot(2,2,4);
surf(x, y, z);
title('surf(x, y, z)')

4（2）
[x,y]=meshgrid(-8:0.5:8);
z=sin(sqrt(x.^2+y^2))./sqrt(x.^2+y.^2+eps);
subplot(2,2,1);
mesh(x, y,z);
title('mesh(x, y,z)')
subplot(2,2,2);
meshc(x, y, z);
title('meshc(x, y,z)')
subplot(2,2,3);
meshz(x, y,z)
title('meshz(x, y,z)')
subplot(2,2,4);
surf(x, y, z);
title('surf(x, y, z)')
el=30;
for az=0:1:240
    view(az,el);
    drawnow;
end

5（1）.
[x,y,z]=sphere(20);
	subplot(1,2,1);
	surf(x,y,z); axis equal;
	light('Posi', [0, 1, 1]);
	shading interp;
	hold on;
	plot3(0, 1, 1, 'p');
	text(0, 1, 1, 'light');
	subplot(1,2,2);
	surf(x, y, z);
	axis equal;
	light('Posi', [1, 0, 1]);
	shading interp;
	hold on;
	plot3(1, 0, 1, 'p'); text(1, 0, 1, 'light');

5（2）
[x,y,z]=sphere(20);
subplot(1,2,1);
surf(x,y,z);
axis equal;
light('Posi', [0, 1, 1]);
shading interp;
hold on;
	plot3(0, 1, 1, 'p');
	text(0, 1, 1, 'light');
	subplot(1,2,2);
	surf(x, y, z);
	axis equal;
	light('Posi', [1, 0, 1]);
	shading interp;
	hold on;
	plot3(1, 0, 1, 'p'); 
    text(1, 0, 1, 'light');
    for i=0:0.1:4*pi
        hold off;
        a=cos(i);
        b=sin(i);
        subplot(1,2,2);
        surf(x,y,z);
        axis equal;
        light('Posi', [a, b, 1]);
        shading interp;
        hold on;
        plot3(a, b, 1, 'p');
        text(a, b, 1, 'light');
        drawnow;
end
6.
function koch(x,y,n)
%x:初始端点横坐标向量：y:初始端点竖坐标向量
%n:迭代次数；
x1=x(1); 
x2=x(2);
y1=y(1);
y2=y(2);
if n>1
    koch([x1,(2*x1+x2)/3],[y1,(2*y1+y2)/3],n-1);
    koch([(2*x1+x2)/3,(x1+x2)/2+(y1-y2)*sqrt(3)/6],[(2*y1+y2)/3,(y1+y2)/2+(x2-x1)*sqrt(3)/6],n-1);
koch([(x1+x2)/2+(y1-y2)*sqrt(3)/6,(x1+2*x2)/3],[(y1+y2)/2+(x2-x1)*sqrt(3)/6,(y1+2*y2)/3],n-1);
    koch([(x1+2*x2)/3,x2],[(y1+2*y2)/3,y2],n-1)
else
    a=[x1,(2*x1+x2)/3,(x1+x2)/2+(y1-y2)*sqrt(3)/6,(x1+2*x2)/3,x2];
    b=[y1,(2*y1+y2)/3,(y1+y2)/2+(x2-x1)*sqrt(3)/6,(y1+2*y2)/3,y2];
    line(a,b);
end

>> koch([0.5,1],[sqrt(3)/2,0],4)

7.
clc;
clear all;
t=(-3*pi:pi/50:3*pi)+eps;
y=sin(t)./t;
subplot(6,1,[2 5]);
hline=plot(t,y);
cm=uicontextmenu;
h_menu=uimenu(gcf,'label','pink');
h_close=uicontrol(gcf,'style','push','position',[10,10,100,25],'string','quit','Callback','Close')
htext=uicontrol('style','text','String','Matlab','Units','normalized','FontSize',12,'position',[0.3,	0.85,0.2,0.1],'Background',[1 1 0]);
cm=uicontextmenu;
uimenu(cm,'label','Red','Callback','set(hline,''color'',''r''),');
uimenu(cm,'label','Yellow','Callback','set(hline,''color'',''y''),');
uimenu(cm,'label','Green','Callback','set(hline,''color'',''g''),');
set(hline,'uicontextmenu',cm);

8.
clc;clear all;
figure('menubar','none');
t=[0:0.001:4*pi];
[x,y]=meshgrid(-8:0.5:8);
z=cos(x)+y;
h_menu=uimenu(gcf,'label','选项');
h_submenu1=uimenu(h_menu,'label','图形','Callback','subplot(6,2,[3 11]);mesh(x,y,z);');
h_submenu2=uimenu(h_menu,'label','图像','Callback','subplot(6,2,[4 12]);plot(t,sin(t));');
h_submenu3=uimenu(h_menu,'label','文字','Callback','uicontrol(''style'',''text'',''string'',''图	像'',''position'',[250,350,60,20])');


9.
function varargout = untitled(varargin)
% UNTITLED M-file for untitled.fig
%      UNTITLED, by itself, creates a new UNTITLED or raises the existing
%      singleton*.
%
%      H = UNTITLED returns the handle to a new UNTITLED or the handle to
%      the existing singleton*.
%
%      UNTITLED('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in UNTITLED.M with the given input arguments.
%
%      UNTITLED('Property','Value',...) creates a new UNTITLED or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before untitled_OpeningFunction gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to untitled_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Copyright 2002-2003 The MathWorks, Inc.

% Edit the above text to modify the response to help untitled

% Last Modified by GUIDE v2.5 06-Jan-2021 15:20:04

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @untitled_OpeningFcn, ...
                   'gui_OutputFcn',  @untitled_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before untitled is made visible.
function untitled_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to untitled (see VARARGIN)

% Choose default command line output for untitled
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes untitled wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = untitled_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;



function f1_input_Callback(hObject, eventdata, handles)
% hObject    handle to f1_input (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of f1_input as text
%        str2double(get(hObject,'String')) returns contents of f1_input as a double


% --- Executes during object creation, after setting all properties.
function f1_input_CreateFcn(hObject, eventdata, handles)
% hObject    handle to f1_input (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc
    set(hObject,'BackgroundColor','white');
else
    set(hObject,'BackgroundColor',get(0,'defaultUicontrolBackgroundColor'));
end



function f2_input_Callback(hObject, eventdata, handles)
% hObject    handle to f2_input (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of f2_input as text
%        str2double(get(hObject,'String')) returns contents of f2_input as a double


% --- Executes during object creation, after setting all properties.
function f2_input_CreateFcn(hObject, eventdata, handles)
% hObject    handle to f2_input (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc
    set(hObject,'BackgroundColor','white');
else
    set(hObject,'BackgroundColor',get(0,'defaultUicontrolBackgroundColor'));
end



function t_input_Callback(hObject, eventdata, handles)
% hObject    handle to t_input (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of t_input as text
%        str2double(get(hObject,'String')) returns contents of t_input as a double


% --- Executes during object creation, after setting all properties.
function t_input_CreateFcn(hObject, eventdata, handles)
% hObject    handle to t_input (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc
    set(hObject,'BackgroundColor','white');
else
    set(hObject,'BackgroundColor',get(0,'defaultUicontrolBackgroundColor'));
end


% --- Executes on button press in pushbutton1.
function pushbutton1_Callback(hObject, eventdata, handles)
f1=str2double(get(handles.f1_input,'String'));
f2=str2double(get(handles.f2_input,'String'));
t=eval(get(handles.t_input,'String'));
x=sin(2*pi*f1*t)+sin(2*pi*f2*t);
y=fft(x,512);
m=y.*conj(y)/512;
f=1000*(0:256)/512;
axes(handles.frequency_axes)
plot(f,m(1:257))
set(handles.frequency_axes,'XminorTick','on')
grid on
axes(handles.time_axes)  
plot(t,x)
set(handles.time_axes,'XminorTick','on')
grid on
% hObject    handle to pushbutton1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)