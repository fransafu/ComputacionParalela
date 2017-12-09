class Curso < ApplicationRecord
  belongs_to :asignatura
  belongs_to :docente
  has_many :horarios
end
