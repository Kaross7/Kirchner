<?php

use Illuminate\Support\Facades\Route;
use App\Http\Controllers\PlanningController; // Zorg ervoor dat je dit toevoegt

/*
|--------------------------------------------------------------------------
| Web Routes
|--------------------------------------------------------------------------
|
| Here is where you can register web routes for your application. These
| routes are loaded by the RouteServiceProvider within a group which
| contains the "web" middleware group. Now create something great!
|
*/

Route::get('/', function () {
    return view('welcome');
})->name('welcome');

Route::get('/page1', function () {
    return view('page1');
})->name('page1');

Route::get('/planning', [PlanningController::class, 'show'])->name('planning.show');
Route::post('/planning/update', [PlanningController::class, 'update'])->name('planning.update');

