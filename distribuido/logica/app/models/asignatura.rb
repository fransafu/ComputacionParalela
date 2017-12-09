class Asignatura < ApplicationRecord
  belongs_to :departamento
  has_many :cursos
end
