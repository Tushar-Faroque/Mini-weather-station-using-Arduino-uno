from django.urls import path
from . import views

urlpatterns = [
    path('', views.home, name='home'),
    path('about/', views.about, name='about'),
    path('ac/', views.ac_room, name='ac'),
    path('kitchen/', views.kitchen, name='kitchen'),
    path('normal/', views.data1_view, name='normal'),
]
